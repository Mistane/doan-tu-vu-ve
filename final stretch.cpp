#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <Time.h>

/*
ok cong viec moi:
tim va viet cai list hoc sinh
tim cach "mem hoa" code
sua vai loi nhu la doan het tu roi ma chua thang
va neu nhap ma dung het thi cung thang
*/

const char *school[] = {"abydos", "gehenna", "Millennium", "Trinity", "Hyakkiyako", "Shanhaijing", "Red Winter", "Valkyrie", "SRT", "Arius"};

void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle

(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , 

Cursor_an_Pos);
}


void gioiThieu(){
	gotoxy(25, 5);
	FILE *ok = fopen("GioiThieu.txt", "rt");
	if(ok == NULL){
		printf("Khong mo duoc file !");
		return;
	}
	char c;
	while(!feof(ok)){
		Sleep(100);
		c = fgetc(ok);
		printf("%c", c);
	}
	fclose(ok);
	getchar();
	system("cls");
}
void dot(){
	printf("\n."); Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500);
}
void nhap(char input[], char box[]){
	input[strlen(input) - 1] = '\0';	
	for(int i = 0; i < strlen(input); i++){
		if(input[i] != ' ')
			box[i] = '_';
		else
			box[i] = ' ';
	}
	box[strlen(input)] = '\0';
}

void xuLi(char input[], char box[], char letter){
	int ok = 0;
	for(int i = 0; i < strlen(input); i++){
		if(box[i] == letter){
			printf("Ban da nhap %c roi!\n", letter); return;
		}
		if(input[i] == letter){
			box[i] = letter;
			ok = 1;
		}
	}
	if(!ok)
		printf("Khong co %c!\n", letter);
	else
		printf("co %c!\n", letter);
}

void hint_help(int n){
	if(n <= 5) printf("Goi y: %s", school[0]);
	else if(n >= 6 && n <= 26) printf("Goi y: %s", school[1]);
	else if(n >= 27 && n <= 48) printf("Goi y: %s", school[2]);
	else if(n >= 49 && n <= 72) printf("Goi y: %s", school[3]);
	else if(n >= 73 && n <= 87) printf("Goi y: %s", school[4]);
	else if(n >= 88 && n <= 94) printf("Goi y: %s", school[5]);
	else if(n >= 95 && n <= 102) printf("Goi y: %s", school[6]);
	else if(n >= 103 && n <= 105) printf("Goi y: %s", school[7]);
	else if(n >= 106 && n <= 109) printf("Goi y: %s", school[8]);
	else if(n >= 110 && n <= 113) printf("Goi y: %s", school[9]);	
}

void game(){
	system("cls");
		int luaChon;
		lmao:
		printf("-------------------------");
		printf("\n1 - Do kho: De");
		printf("\n2 - Do kho: Trung binh");
		printf("\n3 - Do kho: Kho vl");
		printf("\nMoi chon do kho: "); scanf("%d", &luaChon); getchar();
		int attemp = 0;
		if(luaChon == 1){
			printf("\nBan co tong cong 5 luot de doan tu\n"); attemp = 5; Sleep(1500); system("cls");	
		}
		else if(luaChon == 2){
			printf("\nBan co tong cong la 3 luot de doan tu\n"); attemp = 3; Sleep(1500); system("cls");
		}
		else if(luaChon == 3){
			printf("\nBan chi co 1 luot de doan tu!!!\n"); attemp = 1; Sleep(1500); system("cls");
		}
		else{
			printf("\nChon cho dung che do di thang ml\n"); Sleep(1500); system("cls");
			goto lmao;
		}
		
		char input[1000], box[1000], hint[1000];
		
		//lay do tu file
		int dem = 0;
		FILE* open = fopen("BA.txt", "r");
		if(!open){
			printf("Loi roi");
		}
		while (fgets(input, sizeof(input), open)) {
        	dem++; //dem co bao nhieu tu trong file
    	}
    	fseek(open, 0, SEEK_SET);
    	
    	srand(time(NULL));
		int n = rand() % dem + 1;
		
		for(int i = 0; i < n; i++){
			fgets(input, 1000, open); //random tu 1 -> n roi chon tu o vi tri thu n
		}
		fclose(open);
		
		//copy dap an
		char orig[1000];
		strcpy(orig, input);
		
		nhap(strlwr(input), box); //strlwr de bo may dau viet hoa
		int cnt = 0; //so luong lan thu
		while(true){
			initial:
			system("cls");
			hint_help(n);
			printf("\nTu can tim la: %s\n", box);
			char letter[1000];
			char answer[1000];
			if(attemp - cnt > 0){
				printf("\nBan con %d lan de thu\n", attemp - cnt);
			}else{
				system("cls");
				hint_help(n);
				printf("\nTu can tim la: %s\n", box);
				dot();
				printf("\nHet luot roi!"); Sleep(750);
				printf("\nDoan tu di nhoc: "); gets(answer);
				if(strcmp(answer, input) == 0){
					dot();
					printf("\nRat gioi! Nhoc da thang\n");
					getchar(); system("cls");
					return;
				}
				else{
					dot();
					printf("\nSkill issue.\n"); Sleep(750);
					printf("Tu can tim: %s", orig);
					getchar(); system("cls");
					return;
				}
			}
			printf("Nhap vao 1 ki tu: "); gets(letter); ++cnt;
			if(strcmp(letter, input) == 0){
				dot();
				printf("\nQua manh\n");
				getchar(); system("cls");
				return;	
			}
			else if(strlen(letter) > 1){
				goto initial;
			}else{
				xuLi(input, box, letter[0]);
				Sleep(1500);
				system("cls");
			}
			if(strcmp(box, input) == 0){
				printf("\nTu can tim la: "); 
				for(int i = 0; i < strlen(box); i++){
					Sleep(250); printf("%c", box[i]);
				} 
				dot();
				printf("\nOk nhoc thang\n");
				getchar(); system("cls");
				return;
			}		
		}				
}

int main(){
	gioiThieu();
	while(true){	
		int choice;
		printf("--------------------");
		printf("\n1 - Choi game ey");
		printf("\n2 - Thoat");
		printf("\nNhap vao lua chon: "); scanf("%d", &choice); getchar();
		if(choice == 1){
			game();
		}
		else if(choice == 2){
			printf("Cam on vi da den");
			return 0;
		}
		else{
			system("cls");
		} 
	}
		
}
