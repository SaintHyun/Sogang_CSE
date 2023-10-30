#include<iostream>
#include<string>
#include "mysql.h"
#pragma comment(lib, "libmySQL.lib")

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "qaz159han!"
#define DB_NAME "kiles1201_db"

using namespace std;

int main()
{
	MYSQL* connection = NULL;
	MYSQL conn;
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;
	int type, choice;
	int cnt = 0;
	int year, K, month;
	FILE* fp;
	char query[3050];
	char* buffer, * temp;
	int size, state = 0, i = 0;
	char temp2[2000];
	char X[15];
	char* val;

	/* mySQL initialization */
	if (mysql_init(&conn) == NULL)
		printf("mysql_init() error!");

	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (const char*)NULL, 0);
	if (connection == NULL)
	{
		printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
		return 1;
	}
	printf("Connection Succeed\n");
	if (mysql_select_db(&conn, DB_NAME))
	{
		printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
		return 1;
	}

	/* create tables && insert tuples */
	fp = fopen("20201564_1.txt", "r");
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	buffer = (char*)malloc((size_t)size + 1);
	memset(buffer, 0, (size_t)size + 1);
	fseek(fp, 0, SEEK_SET);
	fread(buffer, size, 1, fp);
	temp = strtok(buffer, ";");
	while (1)
	{
		if (temp == NULL) break;
		sprintf(query, "%s", temp);
		state = mysql_query(connection, query);
		temp = strtok(NULL, ";");
	}
	fclose(fp);

	/* select query */
	while (1)
	{
		printf("------- SELECT QUERY TYPES -------\n\n");
		printf("\t1. TYPE 1\n");
		printf("\t2. TYPE 2\n");
		printf("\t3. TYPE 3\n");
		printf("\t4. TYPE 4\n");
		printf("\t5. TYPE 5\n");
		printf("\t6. TYPE 6\n");
		printf("\t7. TYPE 7\n");
		printf("\t0. QUIT\n");
		printf("----------------------------------\n");
		printf("\nInput(TYPE) : ");
		scanf("%d", &type);
		getchar();
		if (type == 0) break;
		switch (type)
		{
		case 1:
			printf("\n");
			printf("------- TYPE 1 -------\n\n");
			printf("** Assume the package shipped by USPS with tracking number X is reported to have been destroyed in an accident. Find the contact information for the customer. **\n");
			printf("What is X?: ");
			scanf("%s", X);
			getchar();
			sprintf(temp2, "select phone_number from Customer as C, Tracking as T, Sale as S, Shipper where T.Tracking_number = S.Tracking_number and S.C_ID = C.C_ID and T.Tracking_number = '%s' and Shipper.name='USPS'",X);
			temp = strtok(temp2, ";");
			sprintf(query, "%s", temp);
			state = mysql_query(connection, query);
			if (state == 0)
			{
				sql_result = mysql_store_result(connection);
				sql_row = mysql_fetch_row(sql_result);
				if (sql_row == NULL)
				{
					printf("Not Exists.\n");
					mysql_free_result(sql_result);
					continue;
				}
				printf("Customer's Contact: %s\n", sql_row[0]);
				mysql_free_result(sql_result);
			}
			while(1)
			{
				printf("\n");
				printf("\n------- Subtypes in TYPE 1 -------\n");
				printf("\t\t1. TYPE 1-1\n");
				printf("\t\t0. QUIT\n");
				printf("\nInput(SUBTYPE) : ");
				scanf("%d", &choice);
				getchar();
				if (choice == 0) break;
				if (choice == 1)
				{
					printf(" ** Then find the contents of that shipment and create a new shipment of replacement items. ** \n");
					sprintf(temp2, "select S.C_ID, S.P_ID, S.S_ID, S.saled_date, S.saled_type, S.pay_type, Shipper.Shipper_ID, S.Sales_ID from Sale as S, Tracking as T, Shipper where S.Tracking_number=T.Tracking_number and T.Tracking_number = '%s' and Shipper.name='USPS'", X);
					temp = strtok(temp2, ";");
					sprintf(query, "%s", temp);
					state = mysql_query(connection, query);
					if (state == 0)
					{
						sql_result = mysql_store_result(connection);
						sql_row = mysql_fetch_row(sql_result);
						if (sql_row == NULL)
						{
							printf("Not Exists.\n");
							mysql_free_result(sql_result);
							continue;
						}
						printf("Customer ID: %s\n", sql_row[0]);
						printf("Product ID: %s\n", sql_row[1]);
						printf("Store ID: %s\n", sql_row[2]);
						printf("Saled date: %s\n", sql_row[3]);
						mysql_free_result(sql_result);
						sprintf(temp2, "delete from Sale where Sale.Tracking_number = '%s'", X);
						temp = strtok(temp2, ";");
						sprintf(query, "%s", temp);
						state = mysql_query(connection, query);
						sprintf(temp2, "delete from Tracking where Tracking.Tracking_number = '%s'", X);
						temp = strtok(temp2, ";");
						sprintf(query, "%s", temp);
						state = mysql_query(connection, query);
						X[4] += 1;
						sprintf(temp2, "insert into Tracking values('%s','%s','%s',NULL)", X, sql_row[6], "20220607");
						temp = strtok(temp2, ";");
						sprintf(query, "%s", temp);
						state = mysql_query(connection, query);
						if (state == 0)
						{
							printf("\nInserted NEW Tracking Data, Tracking_number is %s\n", X);
						}
						//printf("inserted tracking");
						sprintf(temp2, "insert into Sale values('%s','%s','%s','%s','%s','%s','%s','%s')", sql_row[7], sql_row[1], sql_row[0], sql_row[2], X, sql_row[3], sql_row[4], sql_row[5]);
						temp = strtok(temp2, ";");
						sprintf(query, "%s", temp);
						state = mysql_query(connection, query);
					}
				}
			}
			break;
		case 2:
			
			printf("\n");
			printf("------- TYPE 2 -------\n\n");
			printf("** Find the customer who has bought the most (by price) in the past year. **\n");
			printf("Which year? : ");
			scanf("%d", &year);
			getchar();
			sprintf(temp2, "select ss.c_id, sum(pp.tot_price * pp.quantity) as s from sale as ss, product as pp where year(ss.saled_date) = '%d' and pp.p_id = ss.p_id group by ss.c_ID order by s desc limit 1", year);
			temp = strtok(temp2, ";");
			sprintf(query, "%s", temp);
			state = mysql_query(connection, query);
			if (state == 0)
			{
				sql_result = mysql_store_result(connection);
				sql_row = mysql_fetch_row(sql_result);
				if (sql_row == NULL)
				{
					printf("Not Exists.\n");
					mysql_free_result(sql_result);
					continue;
				}
				printf("Customer's ID: %s\n", sql_row[0]);
				val = sql_row[0];
				mysql_free_result(sql_result);

				while (1)
				{
					printf("\n");
					printf("\n------- Subtypes in TYPE 2 -------\n");
					printf("\t\t1. TYPE 2-1\n");
					printf("\t\t0. QUIT\n");
					printf("\nInput(SUBTYPE) : ");
					scanf("%d", &choice);
					getchar();
					if (choice == 0) break;
					if (choice == 1)
					{
						printf(" ** Then find the product that the customer bought the most. ** \n");
						sprintf(temp2, "select ss.p_ID, ss.c_id, sum(p.quantity * p.tot_price) as cnt from customer as CC, Sale as ss, product as p where cc.c_id = ss.c_id and ss.p_id = p.p_id and ss.c_id = '%s' group by ss.p_ID order by cnt desc limit 1", val);
						temp = strtok(temp2, ";");
						sprintf(query, "%s", temp);
						state = mysql_query(connection, query);
						if (state == 0)
						{
							sql_result = mysql_store_result(connection);
							sql_row = mysql_fetch_row(sql_result);
							if (sql_row == NULL)
							{
								printf("Not Exists.\n");
								mysql_free_result(sql_result);
								continue;
							}
							printf("Product ID: %s\n", sql_row[0]);
							val = sql_row[1];
							mysql_free_result(sql_result);
						}
					}
				}
			}
			break;
		case 3:
			printf("\n");
			printf("------- TYPE 3 -------\n\n");
			printf("** Find all products sold in the past year. **\n");
			printf("Which year? : ");
			scanf("%d", &year);
			getchar();
			sprintf(temp2, "select distinct s.p_id from sale as s where year(s.saled_date)='%d'", year);
			temp = strtok(temp2, ";");
			sprintf(query, "%s", temp);
			state = mysql_query(connection, query);
			if (state == 0)
			{
				sql_result = mysql_store_result(connection);
				sql_row = mysql_fetch_row(sql_result);
				if (sql_row == NULL)
				{
					printf("Not Exists.\n");
					mysql_free_result(sql_result);
					continue;
				}
				printf("Product ID\n");
				printf("%s\n", sql_row[0]);
				while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
				{
					printf("%s\n", sql_row[0]);
				}
				mysql_free_result(sql_result);
				printf("\n");
				while (1)
				{
					printf("\n------- Subtypes in TYPE 3 -------\n");
					printf("\t\t1. TYPE 3-1\n");
					printf("\t\t2. TYPE 3-2\n");
					printf("\t\t0. QUIT\n");
					printf("\nInput(SUBTYPE) : ");
					scanf("%d", &choice);
					if (choice == 0) break;
					if (choice == 1)
					{
						printf(" ** Then find the top k products by dollar-amount sold. ** \n");
						printf("Which K? : ");
						scanf("%d", &K);
						getchar();
						sprintf(temp2, "select ss.p_ID, sum(p.quantity * p.tot_price) as cnt from customer as CC, Sale as ss, product as p where cc.c_id = ss.c_id and ss.p_id = p.p_id and year(ss.saled_date) = '%d' group by ss.p_ID order by cnt desc limit %d", year,K);
						temp = strtok(temp2, ";");
						sprintf(query, "%s", temp);
						state = mysql_query(connection, query);
						if (state == 0)
						{
							sql_result = mysql_store_result(connection);
							sql_row = mysql_fetch_row(sql_result);
							if (sql_row == NULL)
							{
								printf("Not Exists.\n");
								mysql_free_result(sql_result);
								continue;
							}
							printf("Product ID \tDollar-amount\n");
							printf("%s\t\t%s\n", sql_row[0], sql_row[1]);
							//int idx = 1;
							while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
							{
								printf("%s\t\t%s\n", sql_row[0],sql_row[1]);
								//idx++;
							}
							mysql_free_result(sql_result);
						}
					}
					if (choice == 2)
					{
						printf(" ** And then find the top 10%% products by dollar-amount sold. ** \n\n");
						sprintf(temp2, "select ss.p_ID, sum(p.quantity * p.tot_price) as cnt from customer as CC, Sale as ss, product as p where cc.c_id = ss.c_id and ss.p_id = p.p_id and year(ss.saled_date) = '%d' group by ss.p_ID order by cnt desc", year);
						temp = strtok(temp2, ";");
						sprintf(query, "%s", temp);
						state = mysql_query(connection, query);
						if (state == 0)
						{
							sql_result = mysql_store_result(connection);
							sql_row = mysql_fetch_row(sql_result);
							if (sql_row == NULL)
							{
								printf("Not Exists.\n");
								mysql_free_result(sql_result);
								continue;
							}
							
							int idx = 0;
							while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
							{
								//printf("%s\t\t%s\n", sql_row[0], sql_row[1]);
								idx++;
							}
							mysql_free_result(sql_result);
							idx /= 10;
							if (idx == 0) idx = 1;
							sprintf(temp2, "select ss.p_ID, sum(p.quantity * p.tot_price) as cnt from customer as CC, Sale as ss, product as p where cc.c_id = ss.c_id and ss.p_id = p.p_id and year(ss.saled_date) = '%d' group by ss.p_ID order by cnt desc limit %d", year, idx);
							temp = strtok(temp2, ";");
							sprintf(query, "%s", temp);
							state = mysql_query(connection, query);
							if (state == 0)
							{
								sql_result = mysql_store_result(connection);
								sql_row = mysql_fetch_row(sql_result);
								if (sql_row == NULL)
								{
									printf("Not Exists.\n");
									mysql_free_result(sql_result);
									continue;
								}
								printf("Product ID \tDollar-amount\n");
								printf("%s\t\t%s\n", sql_row[0], sql_row[1]);
								//K = idx;
								//idx = 1;
								while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
								{
									printf("%s\t\t%s\n", sql_row[0], sql_row[1]);
									//idx++;
								}
							}
						}
					}
				}
			}
			break;
		case 4:
			printf("\n");
			printf("------- TYPE 4 -------\n\n");
			printf("** Find all products by unit sales in the past year. **\n");
			printf("Which year? : ");
			scanf("%d", &year);
			getchar();
			sprintf(temp2, "select s.sales_id, s.p_id, s.saled_date, p.quantity from product as p, sale as s where p.p_id=s.p_id and year(s.saled_date)='%d' order by s.sales_id", year);
			temp = strtok(temp2, ";");
			sprintf(query, "%s", temp);
			state = mysql_query(connection, query);
			if (state == 0)
			{
				sql_result = mysql_store_result(connection);
				sql_row = mysql_fetch_row(sql_result);
				if (sql_row == NULL)
				{
					printf("Not Exists.\n");
					mysql_free_result(sql_result);
					continue;
				}
				printf("\nSaled ID \tProduct ID \tSaled_date \tQuantity\n");
				printf("%s\t\t%s\t\t%s\t\t%s\n", sql_row[0], sql_row[1], sql_row[2],sql_row[3]);
				while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
				{
					printf("%s\t\t%s\t\t%s\t\t%s\n", sql_row[0], sql_row[1], sql_row[2],sql_row[3]);
				}
				mysql_free_result(sql_result);
				printf("\n");
				while (1)
				{
					printf("\n------- Subtypes in TYPE 4 -------\n");
					printf("\t\t1. TYPE 4-1\n");
					printf("\t\t2. TYPE 4-2\n");
					printf("\t\t0. QUIT\n");
					printf("\nInput(SUBTYPE) : ");
					scanf("%d", &choice);
					if (choice == 0) break;
					if (choice == 1)
					{
						printf(" ** Then find the top k products by unit sales. ** \n");
						printf("Which K? : ");
						scanf("%d", &K);
						getchar();
						sprintf(temp2, "select ss.p_ID, sum(p.quantity) as cnt from customer as CC, Sale as ss, product as p where cc.c_id = ss.c_id and ss.p_id = p.p_id and year(ss.saled_date) = '%d' group by ss.p_ID order by cnt desc limit %d", year, K);
						temp = strtok(temp2, ";");
						sprintf(query, "%s", temp);
						state = mysql_query(connection, query);
						if (state == 0)
						{
							sql_result = mysql_store_result(connection);
							sql_row = mysql_fetch_row(sql_result);
							if (sql_row == NULL)
							{
								printf("Not Exists.\n");
								mysql_free_result(sql_result);
								continue;
							}
							printf("Product ID \tQuantity\n");
							printf("%s\t\t%s\n", sql_row[0], sql_row[1]);
							//int idx = 1;
							while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
							{
								printf("%s\t\t%s\n", sql_row[0], sql_row[1]);
								//idx++;
							}
							mysql_free_result(sql_result);
						}
					}
					if (choice == 2)
					{
						printf(" ** And then find the top 10%% products by unit sales. ** \n\n");
						sprintf(temp2, "select ss.p_ID, sum(p.quantity) as cnt from customer as CC, Sale as ss, product as p where cc.c_id = ss.c_id and ss.p_id = p.p_id and year(ss.saled_date) = '%d' group by ss.p_ID order by cnt desc", year);
						temp = strtok(temp2, ";");
						sprintf(query, "%s", temp);
						state = mysql_query(connection, query);
						if (state == 0)
						{
							sql_result = mysql_store_result(connection);
							sql_row = mysql_fetch_row(sql_result);
							if (sql_row == NULL)
							{
								printf("Not Exists.\n");
								mysql_free_result(sql_result);
								continue;
							}

							int idx = 0;
							while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
							{
								//printf("%s\t\t%s\n", sql_row[0], sql_row[1]);
								idx++;
							}
							mysql_free_result(sql_result);
							idx /= 10;
							if (idx == 0) idx = 1;
							sprintf(temp2, "select ss.p_ID, sum(p.quantity) as cnt from customer as CC, Sale as ss, product as p where cc.c_id = ss.c_id and ss.p_id = p.p_id and year(ss.saled_date) = '%d' group by ss.p_ID order by cnt desc limit %d", year,idx);
							temp = strtok(temp2, ";");
							sprintf(query, "%s", temp);
							state = mysql_query(connection, query);
							if (state == 0)
							{
								sql_result = mysql_store_result(connection);
								sql_row = mysql_fetch_row(sql_result);
								if (sql_row == NULL)
								{
									printf("Not Exists.\n");
									mysql_free_result(sql_result);
									continue;
								}
								printf("Product ID \tQuantity\n");
								printf("%s\t\t%s\n", sql_row[0], sql_row[1]);
								K = idx;
								idx = 1;
								while ((sql_row = mysql_fetch_row(sql_result)) != NULL && idx < K)
								{
									printf("%s\t\t%s\n", sql_row[0], sql_row[1]);
									idx++;
								}
							}
						}
					}
				}
			}
			break;
		case 5:
			printf("\n");
			printf("------- TYPE 5 -------\n\n");
			printf("** Find those products that are out-of-stock at every store in California. **\n");
			sprintf(temp2, "select p.p_id, p.type, p.tot_price, c.com_id from product as p, component as c, package as pa, management as m, store as s where pa.p_id = p.p_id and pa.com_id = c.com_id and m.com_id = c.com_id and s.s_id = m.s_id and s.region = 'California' and (m.store_amount = '0' AND m.warehouse_amount = '0')");
			temp = strtok(temp2, ";");
			sprintf(query, "%s", temp);
			state = mysql_query(connection, query);
			if (state == 0)
			{
				sql_result = mysql_store_result(connection);
				sql_row = mysql_fetch_row(sql_result);
				if (sql_row == NULL)
				{
					printf("Not Exists.\n");
					mysql_free_result(sql_result);
					continue;
				}
				printf("Product ID \tProduct type \tProduct price \tComponent ID\n");
				printf("%s\t\t%s\t\t%s\t\t%s\n", sql_row[0],sql_row[1],sql_row[2],sql_row[3]);
				while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
				{
					printf("%s\t\t%s\t\t%s\t\t%s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
				}
				mysql_free_result(sql_result);
				printf("\n");
			}
			break;
		case 6:
			printf("\n");
			printf("------- TYPE 6 -------\n\n");
			printf("** Find those packages that were not delivered within the promised time. **\n");
			sprintf(temp2, "select s.s_id, t.tracking_number, t.expected_date, t.arrived_date from sale as s, tracking as t where t.tracking_number = s.tracking_number and t.expected_date < t.arrived_date");
			temp = strtok(temp2, ";");
			sprintf(query, "%s", temp);
			state = mysql_query(connection, query);
			if (state == 0)
			{
				sql_result = mysql_store_result(connection);
				sql_row = mysql_fetch_row(sql_result);
				if (sql_row == NULL)
				{
					printf("Not Exists.\n");
					mysql_free_result(sql_result);
					continue;
				}
				printf("Sales ID \tTracking Number \tExpected date \t\tArrived date\n");
				printf("%s\t\t%s\t\t%s\t\t%s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
				while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
				{
					printf("%s\t\t%s\t\t%s\t\t%s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
				}
				mysql_free_result(sql_result);
				printf("\n");
			}
			break;
		case 7:
			printf("\n");
			printf("------- TYPE 7 -------\n\n");
			printf("** Generate the bill for each customer for the past month. **\n");
			printf("Which year? : ");
			scanf("%d", &year);
			printf("Which month? : ");
			scanf("%d", &month);
			getchar();
			sprintf(temp2, "create table bill as select c.c_id, c.name, c.phone_number, sum(p.tot_price * p.quantity) as tot_bill from customer as c, sale as s , product as p where s.c_id = c.c_id and p.p_id = s.p_id and year(s.saled_date)='%d' and month(s.saled_date)='%d' group by c.c_id", year, month);
			temp = strtok(temp2, ";");
			sprintf(query, "%s", temp);
			state = mysql_query(connection, query);
			if (state == 0)
			{
				sprintf(temp2, "select * from bill");
				temp = strtok(temp2, ";");
				sprintf(query, "%s", temp);
				state = mysql_query(connection, query);
				if (state == 0)
				{
					sql_result = mysql_store_result(connection);
					sql_row = mysql_fetch_row(sql_result);
					if (sql_row == NULL)
					{
						printf("Not Exists.\n");
						mysql_free_result(sql_result);
						continue;
					}
					printf("Customer ID \tCustomer name \tCustomer Contact \tTotal bill\n");
					printf("%s\t\t%s\t\t%s\t\t%s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
					{
						printf("%s\t\t%s\t\t%s\t\t%s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
					}
					mysql_free_result(sql_result);
					printf("\n");
				}
				sprintf(temp2, "drop table bill");
				temp = strtok(temp2, ";");
				sprintf(query, "%s", temp);
				state = mysql_query(connection, query);
			}
			break;
		}
		
	}

	/* delete tuples && drop tables*/
	fp = fopen("20201564_2.txt", "r");
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	buffer = (char*)malloc((double)size + 1);
	memset(buffer, 0, (double)size + 1);
	fseek(fp, 0, SEEK_SET);
	fread(buffer, size, 1, fp);
	temp = strtok(buffer, ";");
	while (1) 
	{
		if (temp == NULL) break;
		sprintf(query, "%s", temp);
		state = mysql_query(connection, query);
		temp = strtok(NULL, ";");
	}
	fclose(fp);
	mysql_close(connection);
}