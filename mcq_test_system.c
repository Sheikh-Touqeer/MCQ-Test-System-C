#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LEN 300

char getAnswer() {

	char ans;
	while(1) {
		printf("Your Answer(A/B/C/D) : ");
		scanf(" %c",&ans);
		ans = toupper(ans);
		if(ans == 'A' || ans == 'B' || ans == 'C' || ans == 'D') {
			return ans;
		} else {
			printf("Invalid!! Enter (A/ B/ C/ D)");
			while(getchar() != '\n');
		}
	}
}

int main() {

	char name[20];
	int choise;
	printf("enter you Name : ");
	scanf(" %[^\n]s",name);

	printf("Hello %s",name);

	while(1) {
		printf("\nMain MAnu\n");
		printf("1)Solve Mcqs \n2)Inser Mcqs \n3)Show Detail \n4)Exit\n");
		scanf("%d",&choise);

		while(choise <1 || choise > 4) {
			printf("Invalid!!! Enter Choise(1-4) : ");
			scanf("%d",&choise);
		}
		int level;
		char filename[300];
		int num;

		switch(choise) {
			case 1: {
				printf("Enter the Difficuilty level : ");
				printf("\n1)Easy\n2)Normal\n3)Hard\n");
				scanf("%d",&level);

				while(level <1 || level >3) {
					printf("Invalid!!! Enter Level(1-3) : ");
					scanf("%d",&level);
				}

				if(level == 1) {
					strcpy(filename,"easy.txt");
				} else if(level == 2) {
					strcpy(filename,"normal.txt");
				} else {
					strcpy(filename,"hard.txt");
				}

				printf("How many mcqs you want to solve : ");
				scanf("%d",&num);

				FILE *fp = fopen(filename,"r");
				if(fp == NULL) {
					printf("File not Found\n");
					return 1;
				}

				char line[MAX_LEN];
				char correct;
				int q = 1, correct_mcqs = 0, wrong_mcqs = 0;

				printf("-----Your M.C.Q's-----\n");

				int totaltime = num *6;
				time_t starttime = time(NULL);

				while(q <= num && fgets(line, sizeof(line), fp)) {
					time_t now = time(NULL);
					if(difftime(now,starttime) >= totaltime) {
						printf("Time's Up\n");
						break;
					}

					printf("\nQuestion No.%d : %s",q,line);
					char opt[4][MAX_LEN];
					int i;
					for(i =0 ; i<4 ; i++) {
						if(!(fgets(opt[i], sizeof(opt[i]), fp)))
							break;
						printf("%s",opt[i]);
					}
					if(fgets(line, sizeof(line), fp)) {
						correct = toupper(line[0]);
					}

					int userAns = getAnswer();
					if(userAns == correct) {
						printf("Correct\n");
						correct_mcqs++;
					} else {
						printf("Wrong !! Correct is %c \n",correct);
						wrong_mcqs++;
					}
					fgets(line, sizeof(line), fp);
					q++;
				}
				fclose(fp);

				time_t endtime = time(NULL);
				double duration = difftime(endtime,starttime);

				printf("\n---Result---\n");
				printf("\nCorrect : %d",correct_mcqs);
				printf("\nWrong   : %d",wrong_mcqs);
				printf("\nTotal Time Taken : %.0f second",duration);

				FILE *fp2 = fopen("quiz_log.txt","a");
				if(fp2) {
					time_t now = time(NULL);
					char *dt = ctime(&now);
					dt[strcspn(dt, "\n")] = '\0';

					fprintf(fp2, "NAme : %s",name);
					fprintf(fp2, "\nLevel : %d",level);
					fprintf(fp2, "\nAttempt : %d",num);
					fprintf(fp2, "\nCorrect : %d",correct_mcqs);
					fprintf(fp2, "\nWrong : %d",wrong_mcqs);
					fprintf(fp2, "\nTime TAken : %.0f seconds",duration);
					fprintf(fp2, "\nDAte : %s",dt);
					fprintf(fp2, "\n\n--------------------------------\n");

					fclose(fp2);
				}
				printf("\nQuiz History Saved\n");
				break;
			}

			case 2: {
				char line[200];
				char filename[200];
				printf("Select Level\n1)Easy\n2)Normal\n3)Hard\n");
				scanf("%d",&level);

				if(level == 1) {
					strcpy(filename,"easy.txt");
				} else if(level == 2) {
					strcpy(filename,"normal.txt");
				} else {
					strcpy(filename,"hard.txt");
				}

				FILE *fp2 = fopen(filename,"a");

				if(fp2 == NULL) {
					printf("File Can not be open ");
					return 1;
				}
				int n;
				printf("How many mcqs you want to add??\n");
				scanf("%d",&n);
				getchar();

				char ques[MAX_LEN], A[MAX_LEN], B[MAX_LEN], C[MAX_LEN], D[MAX_LEN], correct;
				int i;
				for(i= 0; i<n ; i++) {
					printf("Enter mcqs : ");
					scanf(" %[^\n]s",ques);

					printf("Option A :");
					scanf(" %[^\n]s",A);
					printf("Option B :");
					scanf(" %[^\n]s",B);
					printf("Option C :");
					scanf(" %[^\n]s",C);
					printf("Option D :");
					scanf(" %[^\n]s",D);

					printf("Correct Option(A/ B/ C/ D) : ");
					scanf(" %c",&correct);
					correct = toupper(correct);
					getchar();

					fprintf(fp2,"%s?\n", ques);
					fprintf(fp2,"A) %s\nB) %s\nC) %s\nD) %s\n%c\n\n", A, B, C, D, correct);
				}
				fclose(fp2);
				printf("\nM.C.Q.'s Added Successfully\n");

				break;
			}

			case 3: {
				printf("---Quiz History----\n");

				FILE *fp2 = fopen("quiz_log.txt","r");
				if(fp2 == NULL) {
					printf("History not found\n");
					return 1;
				}
				char line[200];
				while(fgets(line, sizeof(line), fp2)) {
					printf(" %s",line);
				}
				fclose(fp2);
				break;
			}

			case 4: {
				printf("\nProgramme Existed");
				return 0;
			}
		}
	}
	return 0;
}
