#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

FILE *fin, *fout;
char *temp1, *temp2, *code;
char buf[1025];
char *inputfile, *outputfile, *generator;
int codeword,dataword,padding_size;
unsigned char padding=0x00;

void start(int argc, char *argv[])
{
    if(argc!=5)
    {
        printf("usage: ./crc_encoder input_file output_file generator dataword_size\n");
        exit(-1);
    }
    fin=fopen(argv[1],"rb");
    if(!fin)
    {
        printf("input file open error.\n");
        exit(-1);
    }
    fout=fopen(argv[2],"wb");
    if(!fout)
    {
        printf("output file open error.\n");
        exit(-1);
    }
    if(strcmp(argv[4],"4") && strcmp(argv[4],"8"))
    {
        printf("dataword size must be 4 or 8\n");
        exit(-1);
    }
}

void calculate_padding_size()
{
    codeword=dataword + strlen(generator)-1; //padding bit를 붙이기 전 codeword 사이즈 계산
    temp1=(char*)malloc(sizeof(char)*(codeword+1));
    if(dataword==4) //dataword가 4면 둘로 나눠야 하므로...
    {
        temp2=(char*)malloc(sizeof(char)*(codeword+1));
        code=(char*)malloc(sizeof(char)*(2*codeword+1));
    }
    else code=(char*)malloc(sizeof(char)*(codeword+1));

    fseek(fin,0,SEEK_END);
    long long input_size=ftell(fin)*8;
    fclose(fin);
    fin=fopen(inputfile,"rb");
    padding_size=(8-(input_size/dataword*codeword)%8)%8;
    int i;
	for(i=0;i<padding_size;i++)
    {
		padding+=0x01;
		buf[i]='0';
	}
	buf[i] = 0;
	
}

void make_codeword_before_modulo_8()
{
    char tmp;
    int i;
    uint8_t selector=0x80;
    tmp=fgetc(fin);
    for(i=0; i<dataword; i++)
    {
        if(tmp&selector) temp1[i]='1';
        else temp1[i]='0';
        selector >>= 1;
    }
    for(i=dataword; i<codeword; i++)
    {
        temp1[i]='0'; //부족한 길이 (generator 때문에)만큼 0을 뒤에 붙여준다.
    } //여기까지 mod2 나눗셈을 하기 전 값을 만든다.

}

void make_codeword_before_modulo_4()
{
    char tmp;
    int i;
    uint8_t selector=0x80;
    tmp=fgetc(fin);
    for(i=0; i<dataword; i++)
    {
        if(tmp&selector) temp1[i]='1';
        else temp1[i]='0';
        selector >>= 1;
    }
    for(i=0; i<dataword; i++)
    {
        if(tmp&selector) temp2[i]='1';
        else temp2[i]='0';
        selector >>= 1;
    }
    for(i=dataword; i<codeword; i++)
    {
        temp1[i]='0';
        temp2[i]='0';
    } //여기까지 mod2 나눗셈을 하기 전 값을 만든다.
}

void modulo_2_division_8(char *code)
{
    int lengen=strlen(generator),i,j,lencode=strlen(code);
    char *tmp=(char*)malloc(sizeof(char)*codeword+1);
    strncpy(tmp,code,lencode);

    for(i=0; i<dataword; i++)
    {
        if(tmp[i]=='1')
        {
            for(j=0; j<lengen; j++)
            {
                if(generator[j]!=tmp[i+j]) tmp[i+j]='1';
                else tmp[i+j]='0';
            }
        }
    }
    strncpy(code+dataword,tmp+dataword,codeword-dataword);

    free(tmp);
}

void modulo_2_division_4(char *temp1, char*temp2)
{
    int lengen=strlen(generator),i,j,lentemp1=strlen(temp1);
    char *tmp=(char*)malloc(sizeof(char)*codeword+1);
    strncpy(tmp,temp1,lentemp1);
    for(i=0; i<dataword; i++)
    {
        if(tmp[i]=='1')
        {
            for(j=0; j<lengen; j++)
            {
                if(generator[j]!=tmp[i+j]) tmp[i+j]='1';
                else tmp[i+j]='0';
            }
        }
    }
    strncpy(temp1+dataword,tmp+dataword,codeword-dataword);
    
    free(tmp);
    int lentemp2=strlen(temp2);
    tmp=(char*)malloc(sizeof(char)*codeword+1);
    strncpy(tmp,temp2,lentemp2);
    for(i=0; i<dataword; i++)
    {
        if(tmp[i]=='1')
        {
            for(j=0; j<lengen; j++)
            {
                if(generator[j]!=tmp[i+j]) tmp[i+j]='1';
                else tmp[i+j]='0';
            }
        }
    }
    strncpy(temp2+dataword,tmp+dataword,codeword-dataword);
    free(tmp);
}

void print()
{
    unsigned char byte;
    int i,j;
    char *cur=buf;
    int len=strlen(buf);
    for(i=0; i<len/8; i++)
    {
        byte=0;
        for(j=7; j>=0; j--)
        {
            if(*cur=='1') byte|=(1<<j);
            cur++;
        }
        fputc(byte,fout);
    }
}

void manage_buffer()
{
    int len, lenbuf=strlen(buf),lencode=strlen(code);
    if(lenbuf+lencode > 1024)
    {
		len = 1024 - lenbuf;
		strncpy(buf+lenbuf, code, len);
		buf[1024]=0;
		print();
		buf[0] = 0;
        strcpy(buf, code+len);
	}
	else strcpy(buf+lenbuf,code);
}
int main(int argc, char *argv[])
{
    start(argc, argv);
    inputfile=argv[1];
    outputfile=argv[2];
    generator=argv[3];
    dataword=atoi(argv[4]);
    calculate_padding_size();
    fputc(padding,fout);
    while(!feof(fin))
    {
        if(dataword==8)
        {
            make_codeword_before_modulo_8();
            modulo_2_division_8(temp1);
            strcpy(code,temp1);
            manage_buffer();
        }
        else if(dataword==4)
        {
            make_codeword_before_modulo_4();
            modulo_2_division_4(temp1, temp2);
            strcpy(code,temp1);
            strcpy(code+strlen(temp1),temp2);
            manage_buffer();
        } 
    }
    if(strlen(buf)!=0) print();
	free(code);
	free(temp1);
	if(dataword== 4) free(temp2);
	fclose(fin);
	fclose(fout);

}