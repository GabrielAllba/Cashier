#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
typedef char string[50];
#define esc 27

// Tim		: newbie :)
// Anggota	: 
// 			- Carolus Seto Arianto / 210711186
// 			- Gabriel Allba Shemi Yuma / 210711150

// g++ Challenge2_newbie.c -o Challenge2_newbie

void red();
void green();
void cyan();
void reset();
void registrasi(int *status_registrasi, string input_username, string input_password);
void login(int *status_registrasi, int *status_login, string login_username, string login_password, string input_username, string input_password);
void input_item(int *status_registrasi, int *status_login, int *jml_blazer, int *jml_cardigan, int *jml_hoodie, int *jml_kemeja, int *status_input_item, float *total_harga);
void shoopingbag(int *status_registrasi, int *status_login, int *jml_blazer, int *jml_hoodie, int *jml_cardigan, int *jml_kemeja, int *max_jml);
void promo_sale(int *status_registrasi, int *status_login, int *status_voucher, string voucher, int *jml_kemeja, int *jml_hoodie);
void payment(int *status_registrasi, int *status_login, int *status_input_item, int *status_voucher, int *jml_blazer, int *jml_cardigan, int *jml_kemeja, int *jml_hoodie, float *total_harga, int *is_payment_ok);
void reset_data(float *total_harga, int *jml_blazer, int *jml_cardigan, int *jml_hoodie, int *jml_kemeja, int *status_input_item, int *is_payment_ok, int *status_voucher);

// MAIN

int main(int argc, char *argv[]) {
	char menu;
	string login_username, login_password, input_username, input_password, voucher;

	int jml_blazer=0, jml_cardigan=0, jml_kemeja=0, jml_hoodie=0, max_jml=0;
	int status_registrasi=0, status_login=0, status_input_item=0, status_voucher=0, is_payment_ok=0;
	float total_harga=0;
	do{
		system("cls");
		red(); 
		printf("\tH&M\n"); 
		reset();
		printf("----------------------\n");
		printf("[1] Registrasi\n");
		printf("[2] Sign In\n");
		printf("[3] Promo Sale\n");
		printf("[4] Input Item\n");
		printf("[5] Shopping Bag\n");
		printf("[6] Payment\n");
		printf("[ESC] Logout\n");
		printf(">>>> ");menu=getch();
		printf("\n");

		switch(menu){
			case '1':
				registrasi(&status_registrasi, input_username, input_password);
				break;
			case '2':
				login(&status_registrasi, &status_login, login_username, login_password, input_username, input_password);
				break;
			case '3':
				promo_sale(&status_registrasi, &status_login, &status_voucher, voucher,&jml_kemeja, &jml_hoodie);
				break;
			case '4':
				input_item(&status_registrasi, &status_login,&jml_blazer, &jml_cardigan, &jml_hoodie, &jml_kemeja, &status_input_item, &total_harga);
				break;
			case '5':
				shoopingbag(&status_registrasi, &status_login,  &jml_blazer, &jml_hoodie, &jml_cardigan, &jml_kemeja, &max_jml);
				break;
			case '6':
				payment(&status_registrasi, &status_login, &status_input_item, &status_voucher, &jml_blazer, &jml_cardigan, &jml_kemeja, &jml_hoodie, &total_harga, &is_payment_ok);
				if(is_payment_ok==1){
					reset_data(&total_harga, &jml_blazer, &jml_cardigan, &jml_hoodie, &jml_kemeja, &status_input_item, &is_payment_ok, &status_voucher);
				}
				break;
			case esc:
				green();
				printf("\n\t[!] Berhasil Logout [!]\n");
				printf("\n\t[!] Selamat tinggal [!]\n");
				reset();
				break;
			default:
				red();
				printf("\n\t[!] Menu tidak tersedia [!]\n");
				reset();
				break;
		}getch();
	}while(menu!=esc);
	return 0;
}

// DEFINISI PROSEDUR DAN FUNGSI

void red(){
	printf("\033[0;31m"); 
}
void green(){
	printf("\033[0;32m");
}
void cyan(){
	printf("\033[0;36m");
}
void yellow(){
	printf("\033[0;33m");
}
void reset(){
	printf("\033[0m"); 
}

// FUNGSI REGISTRASI

void registrasi(int *status_registrasi, string input_username, string input_password){
	if(*status_registrasi==1){
		red();
		printf("\n\t[!] Anda Sudah Pernah Registrasi [!]\n");
		reset();
	}else{
		do{
			printf("Username : ");fflush(stdin);gets(input_username);
			if(strlen(input_username)<8){
				red();
				printf("\n\t[!] Username minimal 8 karakter [!]\n\n");
				reset();
			}
		}while(strlen(input_username)<8);

		int status_uppercase=0, status_lowercase=0, status_num=0, status_symbol=0;
		do{
			printf("Password : ");fflush(stdin);gets(input_password);
			int i;

			for(i=0; i < strlen(input_password); i++){
				if((input_password[i] >= 'a' && input_password[i]<='z')){
					status_lowercase = 1;
				}else if(input_password[i] >= 'A' && input_password[i]<='Z'){
					status_uppercase = 1;
				}else if(input_password[i]>= '0' && input_password[i]<= '9'){
					status_num = 1;
				}else{
					status_symbol = 1;
				}
			}
			if(strlen(input_password)<8 || status_lowercase== 0 || status_uppercase==0 || status_num==0 || status_symbol==0){
				red();
				printf("\n\t[!] Password harus terdiri dari minimal 8 karakter, huruf besar, kecil, angka dan simbol [!]\n");
				reset();
				status_lowercase=0;
				status_uppercase=0;
				status_num=0;
				status_symbol=0;
			}else{
				green();
				printf("\n\t[!] Register Berhasil [!]\n");
				reset();
				*status_registrasi=1;
			}
		}while(strlen(input_password)<8 || status_lowercase== 0 || status_uppercase==0 || status_num==0 || status_symbol==0);
	}
}

// FUNGSI LOGIN

void login(int *status_registrasi, int *status_login, string login_username, string login_password, string input_username, string input_password){
	if(*status_registrasi==0){
		red();
		printf("\n\t[!] Anda Belum Registrasi [!]\n");
		reset();
	}
	else if(*status_login==1){
		red();
		printf("\n\t[!] Anda Sudah Pernah Login [!]\n");
		reset();
	}
	else{
		do{
			printf("Username : ");fflush(stdin);gets(login_username);
			if(strcmp(login_username, input_username)!=0){
				red();
				printf("\n\t[!] Username Salah [!]\n");
				reset();
			}
		}while(strcmp(login_username, input_username)!=0);

		do{
			printf("Password : ");fflush(stdin);gets(login_password);
			if(strcmp(login_password, input_password)!=0){
				red();
				printf("\n\t[!] Password Salah [!]\n");
				reset();
			}
		}while(strcmp(login_password, input_password)!=0);
		
		string input_captcha;
		char lowercase, uppercase, num;
		char string_captcha[5];
		int i;
		srand(time(NULL));
		
		do{
			for(i=0; i <2; i++){
			
				// ASCII CODE
				uppercase= (rand() % (90  - 65 + 1)) + 65;
				lowercase= (rand() % (122 - 97 + 1)) + 97;
				num= (rand() % (57 - 48 + 1)) + 48;
				// 1, 4    2, 5,     3. 6
				if(i==0){
					int first, second, third;
					first = i;
					second = i+1;
					third=i+2;

					string_captcha[first]=uppercase;
					string_captcha[second]=lowercase;
					string_captcha[third]=num;
					
				}else{
					int forth, fifth, sixth;
					forth= i+2;
					fifth = i+3;
					sixth=i+4;

					string_captcha[forth]=uppercase;
					string_captcha[fifth]=lowercase;
					string_captcha[sixth]=num;			
				}
			}

			printf("\n\t%s", string_captcha);
			printf("\n\tCaptcha : ");fflush(stdin);gets(input_captcha);
			if(strcmp(input_captcha, string_captcha)!=0){
				red();
				printf("\n\t [!] Captcha Tidak Valid [!]\n");
				reset();
			}

		}while(strcmp(input_captcha, string_captcha)!=0);
		green();
		printf("\n\t[!] Login Berhasil [!]\n");
		reset();
		*status_login=1;
	}
}

// PROSEDUR INPUT ITEM
void input_item(int *status_registrasi, int *status_login,int *jml_blazer, int *jml_cardigan, int *jml_hoodie, int *jml_kemeja, int *status_input_item, float *total_harga){
	if(*status_registrasi==0){
		red();
		printf("\n\t[!] Anda belum Registrasi [!]\n");
		reset();
	}else if(*status_login==0){
		red();
		printf("\n\t[!] Anda belum Login [!]\n");
		reset();
	}else{
		string jenis_barang;
		int jml;
		float total_harga_blazer=0, total_harga_cardigan=0, total_harga_hoodie=0, total_harga_kemeja=0;
		printf("Menu Input\n");
		printf("[1] Blazer\n");
		printf("[2] Cardigan\n");
		printf("[3] Kemeja\n");
		printf("[4] Hoodie\n");
		printf("Jenis item yang ingin dimasukkan ke dalam keranjang? [Blazer/Cardigan/Kemeja/Hoodie]\n");
		do{
			printf(">>>> ");fflush(stdin);gets(jenis_barang);
			if(strlen(jenis_barang)==0){
				red();
				printf("\n\t[!] Inputan Kosong [!]\n");
				reset();
			}
		}while(strlen(jenis_barang)==0);

		if(strcmpi(jenis_barang, "Blazer")==0 || strcmpi(jenis_barang, "Cardigan")==0
		|| strcmpi(jenis_barang, "Kemeja")==0 || strcmpi(jenis_barang, "Hoodie")==0){
			do{
				printf("\nJumlah Pembelian : ");

				// check whether the input is character or not
				if(scanf("%d", &jml)==0){
					jml=1;
					break;
				}

				if(jml<=0||jml>3){
					red();
					printf("\n\t[!] Jumlah tidak boleh kurang dari sama dengan 0 dan maksimal 3 [!]\n");
					reset();
				}
				

			}while(jml<=0 || jml >3 );

			if(strcmpi(jenis_barang, "Blazer")==0){
				*jml_blazer+=jml;
				total_harga_blazer=200000*jml;
			}else if(strcmpi(jenis_barang, "Cardigan")==0){
				total_harga_cardigan=250000*jml;
				*jml_cardigan+=jml;
			}else if(strcmpi(jenis_barang, "Hoodie")==0){
				*jml_hoodie+=jml;
				total_harga_hoodie=300000*jml;
			}else{
				*jml_kemeja+=jml;
				total_harga_kemeja=150000*jml;
			}
			*total_harga=*total_harga+total_harga_cardigan+total_harga_blazer+total_harga_kemeja+total_harga_hoodie;
			green();
			printf("\n\t^^ Berhasil Memasukkan Ke Keranjang ^^\n");
			reset();
			*status_input_item =1;
		}else{
			red();
			printf("\n\t[!] Inputan Salah [!]\n");
			reset();
		}

	}
}

// PROSEDUR PROMO SALE 

void promo_sale(int *status_registrasi, int *status_login, int *status_voucher, string voucher, int *jml_kemeja, int *jml_hoodie){


	if(*status_registrasi==0){
		red();
		printf("\n\t[!] Anda belum Registrasi [!]\n");
		reset();
	}else if(*status_login==0){
		red();
		printf("\n\t[!] Anda belum Login [!]\n");
		reset();
	}else if(*status_voucher!=0){
		red();
		printf("\n\t[!] Voucher Telah Diambil Sebelumnya [!]\n");
		reset();
	}else if(*jml_kemeja>=3 && *jml_hoodie>=1){
		
		srand(time(NULL));
		int random_voucher;
		random_voucher = (rand() % (3 - 1 + 1)) + 1;
		if(random_voucher==1){
			strcpy(voucher, "bronze");
			*status_voucher=10;
		}else if(random_voucher==2){
			strcpy(voucher, "silver");
			*status_voucher=25;
		}else{
			strcpy(voucher, "gold");
			*status_voucher=50;
		}
		printf("\n\t[!] Selamat anda mendapatkan %s voucher [!]\n", voucher);
	}
	else{
		int print178 = 178;
		int counting178, i; 
		for(counting178=1; counting178<=20; counting178++){
			printf("%c", print178);
		}
		
	}
}

// SHOPPING BAG

void shoopingbag(int *status_registrasi, int *status_login, int *jml_blazer, int *jml_hoodie, int *jml_cardigan, int *jml_kemeja, int *max_jml){

	// ║ kodenya : 186
	// ═ kodenya : 205 
	int print186 = 186;
	int print205 = 205; 

	if(*status_registrasi==0){
		red();
		printf("\n\t[!] Anda belum Registrasi [!]\n");
		reset();
	}else if(*status_login==0){
		red();
		printf("\n\t[!] Anda belum Login [!]\n");
		reset();
	}
	else{
		printf("\nShooping Bag\n");

		// logic cari terbanyak
		
		if(*jml_blazer>=*jml_cardigan && *jml_blazer>=*jml_hoodie && *jml_blazer>=*jml_kemeja){
			*max_jml=*jml_blazer;
		}
		else if (*jml_cardigan>=*jml_blazer && *jml_cardigan>=*jml_hoodie && *jml_cardigan>=*jml_kemeja) {
			*max_jml = *jml_cardigan;
		}
		else if (*jml_hoodie>=*jml_blazer && *jml_hoodie>=*jml_cardigan && *jml_hoodie>=*jml_kemeja){
			*max_jml = *jml_hoodie;
		}
		else{
			*max_jml=*jml_kemeja;	
		}
		
		int i, x, y, j;
		int column = 5;
		int counter_cardigan=*jml_cardigan, counter_blazer=*jml_blazer, counter_kemeja=*jml_kemeja, counter_hoodie=*jml_hoodie;

		// mencari column
		for(x=0; x<*max_jml;x++){
			column+=3;
		}
		for(i=1;i<=9;i++){ 
			for(j=1;j<=column; j++){
				if(i==1 || i==9){
					if(j==1 || j==column){
						printf("%c", print186);
					}else{
						printf("%c", print205);
					}
				}else if(i%2==0){
					// barisnya br cn ka he
					if(j==1 || j==column){
						printf("%c", print186);
					}else{
						if(i==2){
							if(j==2){
								printf("BR|");
								j=4;
							}else{
								if(j%3==0){
									counter_blazer-=1;
									if(counter_blazer>=0){
										red();
										printf("[]");
										reset();
										j++;
									
									}else{
										printf(" ");
									}
								}
								else{
									printf(" ");
								}
							}
						}else if(i==4){
							if(j==2){
								printf("CN|");
								j=4;
							}else{
								if(j%3==0){
									counter_cardigan-=1;
									if(counter_cardigan>=0){
										yellow();
										printf("()");
										reset();
										j++;
									
									}else{
										printf(" ");
									}
								}
								else{
									printf(" ");
								}
							}
						}else if(i==6){
							if(j==2){
								printf("KA|");
								j=4;
							}else{
								if(j%3==0){
									counter_kemeja-=1;
									if(counter_kemeja>=0){
										cyan();
										printf("{}");
										reset();
										j++;
									}else{
										printf(" ");
									}
								}
								else{
									printf(" ");
								}
							}
						}else{
							if(j==2){
								printf("HE|");
								j=4;
							}else{
								if(j%3==0){
									counter_hoodie-=1;
									if(counter_hoodie>=0){
										green();
										printf("<>");
										reset();
										j++;
									}else{
										printf(" ");
									}
								}
								else{
									printf(" ");
								}
							}
						}
					}
				}else{
					if(j==1 || j==column){
						printf("%c", print186);
					}else{
						printf(" ");
					}
				}
			} 
			printf("\n");
		} 
	}
}
// PROSEDUR PAYMENT 

void payment(int *status_registrasi, int *status_login, int *status_input_item, int *status_voucher , int *jml_blazer, int *jml_cardigan, int *jml_kemeja, int *jml_hoodie, float *total_harga, int *is_payment_ok){
	if(*status_registrasi==0){
		red();
		printf("\n\t[!] Anda belum Registrasi [!]\n");
		reset();
	}else if(*status_login==0){
		red();
		printf("\n\t[!] Anda belum Login [!]\n");
		reset();
	}else if(*status_input_item==0){
		red();
		printf("\n\t[!] Anda belum Input Data [!]\n");
		reset();
	}
	else{
		printf("\n\t\tShopping Bag\n\n");
		if(*jml_cardigan!=0){
			printf(">>\tNama Item : Cardigan\n");
			printf("  \tCode Item: CN\n");
			printf("  \tJumlah: %d\n\n", *jml_cardigan);
		}
		if(*jml_blazer!=0){
			printf(">>\tNama Item : Blazer\n");
			printf("  \tCode Item: BR\n");
			printf("  \tJumlah: %d\n\n", *jml_blazer);
		}
		if(*jml_kemeja!=0){
			printf(">>\tNama Item : Kemeja\n");
			printf("  \tCode Item: KA\n");
			printf("  \tJumlah: %d\n\n", *jml_kemeja);
		}
		if(*jml_hoodie!=0){
			printf(">>\tNama Item : Hoodie\n");
			printf("  \tCode Item: HE\n");
			printf("  \tJumlah: %d\n\n", *jml_hoodie);
		}
		string ingin_checkout, ingin_pakai_voucher;
		float input_uang, kembalian;

		printf("Apakah ingin Check Out Belanjaan ? [Ya | Tidak] : ");fflush(stdin);gets(ingin_checkout);
		if(strcmpi(ingin_checkout, "ya")==0){

			printf("\nApakah ingin menggunakan voucher ? [Ya | Tidak] : ");fflush(stdin);gets(ingin_pakai_voucher);
			if(strcmpi(ingin_pakai_voucher, "ya")==0){
				if(*status_voucher==0){
					red();
					printf("\n[!] Voucher Tidak ada [!]\n");
					reset();
				}else{
					green();
					printf("\n[!] Voucher Berhasil digunakan [!]\n");
					reset();
					*total_harga=*total_harga-(*status_voucher*(*total_harga)/100);
					*status_voucher=0;
				}
			}else{
				printf("\n[!] Voucher Tidak digunakan [!]\n");
			}
			printf("\nTotal Harga : Rp. %.2f\n", *total_harga);

			do{
				printf("\nMasukkan uang : Rp. ");scanf("%f", &input_uang);
				if(input_uang<*total_harga){
					red();
					printf("\n\t[!] Uang tidak cukup [!]\n");
					reset();
				}else{
					kembalian=input_uang-(*total_harga);
					printf("\nKembalian : Rp. %.2f\n", kembalian);
					green();
					printf("\n\t[!] Transaksi Berhasil [!]");
					printf("\n\t[!] Keranjang Berhasil dikosongkan [!]\n");
					reset();
					
					*is_payment_ok = 1;
				}
			}while(input_uang<*total_harga);

		}else{
			red();
			printf("\n\t[!] Barang belanjaan tidak jadi di Checkout, Silahkan Belanja Lagi [!]\n");
			reset();
		}

	}
}

// NETT EFFECT RESET DATA

void reset_data(float *total_harga, int *jml_blazer, int *jml_cardigan, int *jml_hoodie, int *jml_kemeja, int *status_input_item, int *is_payment_ok, int *status_voucher){
	*total_harga=0;
	*jml_blazer=0;
	*jml_cardigan=0;
	*jml_hoodie=0;
	*jml_kemeja=0;
	*status_input_item=0;
	*is_payment_ok=0;
	*status_voucher=0;
}