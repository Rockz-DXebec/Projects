#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
	printf("---------------------------------------------------\n");
	printf("        WELCOME TO ROCKZ CAR RENTAL SYSTEM     \n");
	printf("---------------------------------------------------\n\n");
	srand(time(0));
	time_t now;
	time(&now);
	while(1) {
		int car,day,choice,ch;
		float INSURANCE_RATE = 0.10,total=0,insurance_cost = 0,Rent,Securitydeposit;
		char name[50];
		printf("\n1)Premium\n2)Sports\n3)Luxury\n4)Exit\nSelect Tier: ");
		scanf("%d",&ch);
		if(ch==4) {
			printf("\nThank you for visiting ROCKZ CAR RENTALS. Have a luxury day ahead!\n");
			break;
		}
		printf("Enter name: ");
		scanf("%s",name);
		printf("Enter number of rental days: ");
		scanf("%d",&day);
		if(ch==1) {
			printf("\n10)Brabus Rocket 900\n20)Mansory P900 Gronos\n30)Pagani Huayra\n40)Ferrari LaFerrari");
			printf("\n50)McLaren Speedtail\n60)Aston Martin Valkyrie\n70)Koenigsegg Jesko\n80)Lamborghini Veneno\n");
			printf("90)Bugatti Chiron SS 300+\n100)Rimac Nevera\nChoose Car: ");
			scanf("%d",&car);
			if(car==10 || car==20) {
				Rent=15000;
				Securitydeposit=60000;
			}
			else if(car==30 || car==40 || car==50) {
				Rent=18000;
				Securitydeposit=75000;
			}
			else if(car==60 || car==70 || car==80) {
				Rent=21000;
				Securitydeposit=85000;
			}
			else if(car==90 || car==100) {
				Rent=25000;
				Securitydeposit=100000;
			}
			else {
				printf("Invalid Choice! Try again\n");
				continue;
			}
		}
		else if(ch==2) {
			printf("\n11)Dodge Hellcat\n22)Corvette Z06\n33)Jaguar F-Type\n44)Nissan GT-R Nismo\n");
			printf("55)Aston Martin Vantage\n66)Porsche 911 GT3 RS\n77)Lamborghini Huracan STO\n88)Ferrari 812 Superfast");
			printf("\n99)McLaren 765LT\n111)Pagani Zonda Cinque\nChoose Car: ");
			scanf("%d",&car);
			if(car==11 || car==22 || car==33) {
				Rent=3500;
				Securitydeposit=9000;
			}
			else if(car==44 || car==55 || car==66) {
				Rent=4500;
				Securitydeposit=12000;
			}
			else if(car==77 || car==88 || car==99) {
				Rent=5500;
				Securitydeposit=18000;
			}
			else if(car==111) {
				Rent=12000;
				Securitydeposit=50000;
			}
			else {
				printf("Invalid Choice! Try again\n");
				continue;
			}
		}
		else if(ch==3) {
			printf("\n101)Lexus LS 500h\n102)BMW 760Li\n103)Audi A8L\n104)Range Rover SV\n");
			printf("105)Maserati Quattroporte\n106)Maybach S680\n107)Bentley Flying Spur\n");
			printf("108)Rolls-Royce Phantom\n109)Brabus 900\n110)Mansory Cullinan\nChoose Car: ");
			scanf("%d",&car);
			if(car==101 || car==102 || car==103) {
				Rent=3000;
				Securitydeposit=8000;
			}
			else if(car==104 || car==105) {
				Rent=4000;
				Securitydeposit=11000;
			}
			else if(car==106 || car==107) {
				Rent=5000;
				Securitydeposit=15000;
			}
			else if(car==108 || car==109 || car==110) {
				Rent=6000;
				Securitydeposit=20000;
			}
			else {
				printf("Invalid Choice! Try again\n");
				continue;
			}
		}
		else {
			printf("Invalid Choice! Try again\n");
			continue;
		}
		total=day*Rent+Securitydeposit;
		printf("\nWould you like to add insurance coverage (10%% extra)?\n");
		printf("1. Yes\n");
		printf("2. No\n");
		printf("Enter choice (1 or 2): ");
		scanf("%d", &choice);

		if (choice == 1) {
			insurance_cost = (day * Rent) * INSURANCE_RATE;
			total += insurance_cost;
		}
		int receiptID = rand() % 100000;
		float discount = 0;
		printf("\n---------------------------------------------------\n");
		printf("                 RENTAL SUMMARY                    \n");
		printf("---------------------------------------------------\n");
		printf("Receipt ID          : #%d\n", receiptID);
		printf("Date & Time         : %s", ctime(&now));
		printf("Customer Name       : %s\n", name);
		printf("Tier Selected       : ");
		switch(ch) {
		case 1:
			printf("Premium\n");
			break;
		case 2:
			printf("Sports\n");
			break;
		case 3:
			printf("Luxury\n");
			break;
		default:
			printf("Unknown\n");
			break;
		}
		printf("Car Selected        : ");
		switch(car) {
		case 10:
			printf("Brabus Rocket 900\n");
			break;
		case 20:
			printf("Mansory P900 Gronos\n");
			break;
		case 30:
			printf("Pagani Huayra\n");
			break;
		case 40:
			printf("Ferrari LaFerrari\n");
			break;
		case 50:
			printf("McLaren Speedtail\n");
			break;
		case 60:
			printf("Aston Martin Valkyrie\n");
			break;
		case 70:
			printf("Koenigsegg Jesko\n");
			break;
		case 80:
			printf("Lamborghini Veneno\n");
			break;
		case 90:
			printf("Bugatti Chiron SS 300+\n");
			break;
		case 100:
			printf("Rimac Nevera\n");
			break;
		case 11:
			printf("Dodge Hellcat\n");
			break;
		case 22:
			printf("Corvette Z06\n");
			break;
		case 33:
			printf("Jaguar F-Type\n");
			break;
		case 44:
			printf("Nissan GT-R Nismo\n");
			break;
		case 55:
			printf("Aston Martin Vantage\n");
			break;
		case 66:
			printf("Porsche 911 GT3 RS\n");
			break;
		case 77:
			printf("Lamborghini Huracan STO\n");
			break;
		case 88:
			printf("Ferrari 812 Superfast\n");
			break;
		case 99:
			printf("McLaren 765LT\n");
			break;
		case 111:
			printf("Pagani Zonda Cinque\n");
			break;
		case 101:
			printf("Lexus LS 500h\n");
			break;
		case 102:
			printf("BMW 760Li\n");
			break;
		case 103:
			printf("Audi A8L\n");
			break;
		case 104:
			printf("Range Rover SV\n");
			break;
		case 105:
			printf("Maserati Quattroporte\n");
			break;
		case 106:
			printf("Maybach S680\n");
			break;
		case 107:
			printf("Bentley Flying Spur\n");
			break;
		case 108:
			printf("Rolls-Royce Phantom\n");
			break;
		case 109:
			printf("Brabus 900\n");
			break;
		case 110:
			printf("Mansory Cullinan\n");
			break;
		default:
			printf("Unknown Car\n");
			break;
		}

		printf("Rent per Day        : $%.2f\n", Rent);
		printf("Days Rented         : %d\n", day);
		printf("Base Rent           : $%.2f\n", day*Rent);
		printf("Security Deposit    : $%.2f\n", Securitydeposit);
		if(day > 5) {
			discount = (day * Rent) * 0.10;
			total -= discount;
			printf("Discount (10%%)      : $%.2f\n", discount);
		}
		if (choice == 1)
			printf("Insurance (10%%)     : $%.2f\n", insurance_cost);
		else
			printf("Insurance            : Not added\n");
		printf("---------------------------------------------------\n");
		printf("Total Amount Payable: $%.2f\n", total);
		printf("---------------------------------------------------\n");
		printf("\nWould you like to rent another car? (1 = Yes, 2 = No): ");
		scanf("%d", &choice);
		if(choice == 2) {
			if(ch == 1)
				printf("\nYou're cruising in true elite style!\n");
			else if(ch == 2)
				printf("\nGet ready to burn some asphalt!\n");
			else
			printf("\nEnjoy your comfort ride in pure elegance!\n");
			printf("Thank you for choosing ROCKZ CAR RENTALS!\n");
			printf("Drive safe and have a great trip!\n");
			break;
		}
	}
	return 0;
}