#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *buf;
FILE *fin,*fout1,*fout2,*ff;
char *temp1, *temp2, *code;
char *inputfile, *outputfile, *generator;
int buffer_size, len;
int errorcnt,totcnt;
int codeword,dataword,padding_size;
unsigned char padding,mask;
char byte_buf[9];
unsigned char temp;

void start(int argc, char *argv[])
{
    if(argc!=6)
    {
        printf("usage: ./crc_decoder input_file output_file result_file generator dataword_size\n");
        exit(-1);
    }
    fin=fopen(argv[1],"rb");
    if(!fin)
    {
        printf("input file open error.\n");
        exit(-1);
    }
    fout1=fopen(argv[2],"wb");
    if(!fout1)
    {
        printf("output file open error.\n");
        exit(-1);
    }
    fout2=fopen(argv[3],"w");
    if(!fout2)
    {
        printf("result file open error.\n");
        exit(-1);
    }
    if(strcmp(argv[5],"4") && strcmp(argv[5],"8"))
    {
        printf("dataword size must be 4 or 8");
        exit(-1);
    }
}

int calculate_padding()
{
    codeword = dataword + strlen(generator)-1;
    unsigned char padding;
    int cnt;
    buf=(char*)malloc(sizeof(char)*(codeword*10+1));
    padding=fgetc(fin);
    for(cnt=0,mask=0x80; padding!=0x00; padding-=0x01,cnt++,mask>>=1);
    return cnt;
}

void remove_padding()
{
    int i;
    unsigned char tmp;
    temp1=(char*)malloc(sizeof(char)*(codeword+1));
    tmp=fgetc(fin);
    if(dataword==4)
    {
        temp2=(char*)malloc(sizeof(char)*(codeword+1));
        code=(char*)malloc(sizeof(char)*(2*codeword+1));
    }
    else code=(char*)malloc(sizeof(char)*codeword+1);
    for(i=padding_size; i<8; i++, mask>>=1)
    {
        if(!(tmp&mask)) buf[i-padding_size]='0';
        else buf[i-padding_size]='1';
    }
    buf[i-padding_size]=0;
}

void binary_to_char()
{
    int i;
    unsigned char tmp=fgetc(fin);
    mask=0x80;
    for(i=0; i<8; i++, mask>>=1)
    {
        if(tmp&mask) byte_buf[i]='1';
        else byte_buf[i]='0';
    }
}

void modulo_2_division(char *code)
{
    //printf("modul\n");
    int lengen=strlen(generator),i,j;
    int lencode=strlen(code);
    char *tmp=(char*)malloc(sizeof(char)*(codeword+1));
    //printf("malloc su\n");
    strncpy(tmp,code,lencode);
    for(i=0; i<dataword; i++)
    {
        if(tmp[i]=='1')
        {
            for(j=0; j<lengen; j++)
            {
                tmp[i+j]=(generator[j]^tmp[i+j])+'0';
            }
        }
    }
    for(i=dataword; i<codeword; i++)
    {
        if(tmp[i]=='1')
        {
            errorcnt++;
            break;
        }
    }
    //printf("beftmp\n");
	free(tmp);
    //printf("afttmp\n");
}

void decoding_print()
{
    //printf("decode\n");
    int i,j;
	char* code = (char*)malloc(sizeof(char)*(codeword + 1));
	char output_buffer[9];
	int idx = 0,lenbuf=strlen(buf);
	unsigned int byte;
	for(i = 0; i<lenbuf/codeword; i++)
    {
		strncpy(code, buf+i*codeword, codeword);
		code[codeword] = 0;
		modulo_2_division(code);
        strncpy(output_buffer+idx,code,dataword);
        idx+=dataword;
		output_buffer[idx]=0;
		if(idx == 8)
        {
			idx = 0;
			byte = 0;
			for(j=7;j>=0;j--)
            {
                byte=byte|((output_buffer[idx++]-'0')<<j);
			}
			fputc(byte,fout1);
			idx = 0;
		}
		totcnt++;
	}
    //printf("befcode\n");
	free(code);
    //printf("aftcode\n");
}

void buffer_manage()
{
    //printf("bufman\n");
    int lenbuf=strlen(buf);
    int len=codeword*10-lenbuf;
    if(lenbuf+8>codeword*10)
    {
        strncpy(buf+lenbuf,byte_buf,len);
        buf[codeword*10]=0;
        decoding_print();
        buf[0]=0;
        strcpy(buf,byte_buf+len);
    }
    else strcpy(buf+lenbuf,byte_buf);
}

int main(int argc, char *argv[])
{
    start(argc, argv);
    inputfile=argv[1];
    outputfile=argv[2];
    generator=argv[4];
    dataword=atoi(argv[5]);
	padding_size=calculate_padding();
    remove_padding();

	int cutlen;
	char byte[9];
    while(!feof(fin))
    {
        binary_to_char();
        //printf("bitochar\n");
        buffer_manage();
		
    }
    if(!strlen(buf)) decoding_print();
    fprintf(fout2, "%d %d\n",totcnt,errorcnt);
    free(code);
	free(temp1);
	if(dataword== 4) free(temp2);
	fclose(fin);
	fclose(fout1);
    fclose(fout2);
}