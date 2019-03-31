void tran_edit()
{
	struct trans trans;
	char ch,curr[35];
    int c,i,j=1,k=0;
 	
	 	title();
		gotoxy(15,10);printf("1. Edit Income Transaction\n");
        gotoxy(15,12);printf("2. Edit Expense Transaction\n");
        gotoxy(15,14);printf("3. Back to Main Menu\n");

        gotoxy(1,17); for(i=0;i<78;i++) printf("_");
        gotoxy(23,20);printf("Press a choice between the range [1-3] ");
        
        switch(getch()-48)
        {
	        case 1:
	        title();
	
	        gotoxy(2,6);puts("S.N.");
	        gotoxy(8,6);puts("Transaction Type");
	        gotoxy(36,6);puts("Date");
	        gotoxy(50,6);puts("Time");
	        gotoxy(61,6);puts("Amount (NRs.)");
	        gotoxy(1,7); for(i=1;i<79;i++) printf("%c",196);
	        
	        fp=fopen("INCOME_T.DAT","r");
	        while(fread(&trans,sizeof(trans),1,fp)==1)
	        {
	        	gotoxy(2,8+j);printf("%d.",trans.c);
	        	gotoxy(8,8+j);printf("%s",trans.t_type);
	        	strcpy(date,trans._date);
	        	date_output(date);
	        	gotoxy(36,8+j);printf("%s",date);
	        	gotoxy(50,8+j);printf("%s",trans._ttime);
	        	currency(curr,trans.amt);
	        	gotoxy(61,8+j);printf("%s",curr);
	        	j++;
			}
			fclose(fp);
			gotoxy(1,20); for(i=0;i<78;i++) printf("_");
	    	gotoxy(3,22);printf("Enter transaction no. to edit or press other key to go back: ");
	    	scanf("%d",&c);
	    	fp=fopen("INCOME_T.DAT","r");
			tfp=fopen("TEMP.DAT","w");
	    	while(fread(&trans,sizeof(trans),1,fp)==1)
			{
		        if(c==trans.c)
		        {	title();
			        gotoxy(15,10);printf("1. Edit Transaction Type\n");
			        gotoxy(15,12);printf("2. Edit Date\n");
			        gotoxy(15,14);printf("3. Back Amount\n");
			
			        gotoxy(1,17); for(i=0;i<78;i++) printf("_");
			        gotoxy(23,20);printf("Press a choice between the range [1-3] ");
			        
			        switch(getch()-48)
			        {
			        	case 1:
			        		title();
							gotoxy(15,7); printf("1. Interest Money\n");
					        gotoxy(15,9); printf("2. Award\n");
					        gotoxy(15,11); printf("3. Salary\n");
					        gotoxy(15,13); printf("4. Gifts\n");
					        gotoxy(15,15); printf("5. Selling\n");
							gotoxy(45,7); printf("6. Others\n");
					
					        gotoxy(1,17); for(i=0;i<78;i++) printf("_");
					        gotoxy(23,20); printf("Press a choice between the range [1-6] ");
					        
					        switch(getch()-48)
					        {
								case 1: strcpy(trans.t_type,"Interest Money"); break;
						        case 2: strcpy(trans.t_type,"Award"); break;
						        case 3: strcpy(trans.t_type,"Salary"); break;
						        case 4: strcpy(trans.t_type,"Gifts"); break;
						        case 5: strcpy(trans.t_type,"Selling"); break;
						        case 6: strcpy(trans.t_type,"Others"); break;
							}
            				fwrite(&trans,sizeof(trans),1,tfp);
            				title();
			    			gotoxy(20,12);printf("Transaction has been sucessfully Edited!");
			    			getch();
						break;
						
						case 2:
							title();
							gotoxy(10,12);printf("Input Date in the format mm/dd/yy:");
							gotoxy(10,13);printf("(Example:02/22/15)");
							gotoxy(45,12);scanf("%s",&trans._date);
            				fwrite(&trans,sizeof(trans),1,tfp);
            				title();
			    			gotoxy(20,12);printf("Transaction has been sucessfully Edited!");
			    			getch();
						break;
						
						case 3:
							title();
							gotoxy(10,13);printf("Input Amount (in NRs.):");
							gotoxy(35,13);scanf("%s",&trans.amt);
            				fwrite(&trans,sizeof(trans),1,tfp);
            				title();
			    			gotoxy(20,12);printf("Transaction has been sucessfully Edited!");
			    			getch();
						break;
			        }
			    }
			else{
		       		fwrite(&trans,sizeof(trans),1,tfp);
		        }
			}
			fclose(fp);
		    fclose(tfp);
            remove("INCOME_T.DAT");
            rename("TEMP.DAT","INCOME_T.DAT");
			break;
			
			case 2:
	        title();
	
	        gotoxy(2,6);puts("S.N.");
	        gotoxy(8,6);puts("Transaction Type");
	        gotoxy(36,6);puts("Date");
	        gotoxy(50,6);puts("Time");
	        gotoxy(61,6);puts("Amount (NRs.)");
	        gotoxy(1,7); for(i=1;i<79;i++) printf("%c",196);
	        
	        fp=fopen("EXPENSE.DAT","r");
	        while(fread(&trans,sizeof(trans),1,fp)==1)
	        {
	        	gotoxy(2,8+j);printf("%d.",trans.c);
	        	gotoxy(8,8+j);printf("%s",trans.t_type);
	        	strcpy(date,trans._date);
	        	date_output(date);
	        	gotoxy(36,8+j);printf("%s",date);
	        	gotoxy(50,8+j);printf("%s",trans._ttime);
	        	currency(curr,trans.amt);
	        	gotoxy(61,8+j);printf("%s",curr);
	        	j++;
			}
			fclose(fp);
			gotoxy(1,20); for(i=0;i<78;i++) printf("_");
	    	gotoxy(3,22);printf("Enter transaction no. to edit or press other key to go back: ");
	    	scanf("%d",&c);
	    	fp=fopen("EXPENSE_T.DAT","r");	    	
			tfp=fopen("TEMP.DAT","w");
	    	while(fread(&trans,sizeof(trans),1,fp)==1)
			{
		        if(c==trans.c)
		        {	title();
			        gotoxy(15,10);printf("1. Edit Transaction Type\n");
			        gotoxy(15,12);printf("2. Edit Date\n");
			        gotoxy(15,14);printf("3. Back Amount\n");
			
			        gotoxy(1,17); for(i=0;i<78;i++) printf("_");
			        gotoxy(23,20);printf("Press a choice between the range [1-3] ");
			        
			        switch(getch()-48)
			        {
			        	case 1:
			        		title();
							gotoxy(15,7); printf("1. Food & Beverage\n");
					        gotoxy(15,9); printf("2. Bills & Utilities\n");
					        gotoxy(15,11); printf("3. Shopping\n");
					        gotoxy(15,13); printf("4. Transportation\n");
					        gotoxy(15,15); printf("5. Friends & Family\n");
							gotoxy(45,7); printf("6. Entertainment\n");
					        gotoxy(45,9); printf("7. Health & Fitness\n");
					        gotoxy(45,11); printf("8. Gift & Donation\n");
					        gotoxy(45,13); printf("9. Others\n");
					        
					        gotoxy(1,17); for(i=0;i<78;i++) printf("_");
					        gotoxy(23,20);printf("Press a choice between the range [1-9] ");
					        
					        switch(getch()-48)
					        {
						        case 1: strcpy(trans.t_type,"Food & Beverage"); break;
						        case 2: strcpy(trans.t_type,"Bills & Utilities"); break;
						        case 3: strcpy(trans.t_type,"Shopping"); break;
						        case 4: strcpy(trans.t_type,"Transportation"); break;
						        case 5: strcpy(trans.t_type,"Friends & Family"); break;
						        case 6: strcpy(trans.t_type,"Entertainment"); break;
						        case 7: strcpy(trans.t_type,"Health & Fitness"); break;
						        case 8: strcpy(trans.t_type,"Gift & Donation"); break;
						        case 9: strcpy(trans.t_type,"Others"); break;
							}
            				fwrite(&trans,sizeof(trans),1,tfp);
            				title();
			    			gotoxy(20,12);printf("Transaction has been sucessfully Edited!");
			    			getch();
						break;
						
						case 2:
							title();
							gotoxy(10,12);printf("Input Date in the format mm/dd/yy:");
							gotoxy(10,13);printf("(Example:02/22/15)");
							gotoxy(45,12);scanf("%s",&trans._date);
            				fwrite(&trans,sizeof(trans),1,tfp);
            				title();
			    			gotoxy(20,12);printf("Transaction has been sucessfully Edited!");
			    			getch();
						break;
						
						case 3:
							title();
							gotoxy(10,13);printf("Input Amount (in NRs.):");
							gotoxy(35,13);scanf("%s",&trans.amt);
            				fwrite(&trans,sizeof(trans),1,tfp);
            				title();
			    			gotoxy(20,12);printf("Transaction has been sucessfully Edited!");
			    			getch();
						break;
			        }
			    }
			else{
		       		fwrite(&trans,sizeof(trans),1,tfp);
		        }			    
			}     
	        break;
	        
	        
	        case 3:getch();
	        break;
	
	        default://when entered characted is not between 1-3
	        {title();
	        gotoxy(12,12); printf("Your input is out of range! Enter a choice between 1 to 3!");
	        gotoxy(26,15); printf("Press any key to continue");
	        getch();}
	    }
}
