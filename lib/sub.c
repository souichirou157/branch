#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <time.h> 
#define NUM_SIZE 4

void shuffle(char numbers[], int num) {
	int i, j;
	char tmp;

	//配列の末尾を指定
	i = num - 1;

	while (i > 0) {
		//シャッフル用の乱数
		j = rand() % (i + 1);

	  //シャッフル
		tmp = numbers[j];
		numbers[j] = numbers[i];
		numbers[i] = tmp;

		
		i--;//シャッフル範囲がだんだん狭くなる
	}
}

//　　　入力した文字が数字化判別 数字なら1を返す　　　　　　　　　　　　　　
int is_allDigit(char input_str[], int len) {
	for (int i = 0; i < len; i++) {
		if (!isdigit(input_str[i])) {
			return 0;
		}
	}
	return 1;
}


//桁の重複がないか判別
int is_allDifferent(char input_str[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (input_str[i] == input_str[j]) {
				return 0;
			}
		}
	}
	return 1;
}


//桁数が4か判別する
void inputNum(char input[], int num_size) {
	char input_str[256];//入力した数字を格納

	while (1) {
	
		scanf("%s",&input_str);
	
		//strlenで桁数を数える４桁になるまで繰り返す
		
		if (strlen(input_str) != num_size) {
			printf("%d桁じゃないです\n", num_size);
			continue;
		}
		
		if (!is_allDigit(input_str, num_size)) {
			printf("数字じゃないのが入ってます...\n");
			continue;
		}

		if (!is_allDifferent(input_str, num_size)) {
			printf("桁に重複がありますやり直し...\n");
			continue;
		}
		
		//桁に重複なければループ抜けられる
		for (int i = 0; i < num_size; i++) {
			input[i] = input_str[i];
		}
		
		break;
	}
}


//正解と入力の比較　場所も文字も同じなら　hitにカウント
int countHit(char input[], char answer[], int num_size) {
	int num_hit = 0;

	for (int i = 0; i < num_size; i++) {
		for (int j = 0; j < num_size; j++) {
			if (answer[i] == input[j]) {
				if (i == j) {
					num_hit++;
				}
			}
		}
	}

	return num_hit;
}


//場所が違うけど同じ数字があればblowに加算
int countBlow(char input[], char answer[], int num_size) {

	int num_blow = 0;

	for (int i = 0; i < num_size; i++) {
		for (int j = 0; j < num_size; j++) {
			if (answer[i] == input[j]) {
				if (i != j) {
					num_blow++;
				}
			}
		}
	}

	return num_blow;
}


int main(void) {

	char answer[NUM_SIZE];//正解格納
	int num_hit, num_blow;
	int rimit = 0;
	
	
	srand((unsigned int)time(NULL));

	
	char numbers[] = {
		'0', '1', '2', '3', '4',
		'5', '6', '7', '8', '9'
	};
	int num = sizeof(numbers) / sizeof(numbers[0]);


	shuffle(numbers, num);
	
	do {


		char input[4];
		inputNum(input, NUM_SIZE);
		printf("\n");

		for (int i = 0; i < NUM_SIZE; i++) {
			srand((unsigned int)time(NULL));

			answer[i] = numbers[i];
			printf("%c", answer[i]);
		}
	
	
		

		
		num_hit = countHit(answer, input, NUM_SIZE);//
		num_blow = countBlow(answer, input, NUM_SIZE);
		printf("\n");
		printf("%d HIT!! | %d BLOW!!\n", num_hit, num_blow);
		

		

	} while (num_hit < NUM_SIZE);

								   
	printf("!!!! GAME_CLEAR !!!!\n");
	printf(" answer = [");
	for (int i = 0; i < NUM_SIZE; i++) {
		printf("%c", answer[i]);
	}
	printf("] \n");

	return 0;
}


























//6月21無限ループ原因探す
//たぶんinput_num関数の
//continue


void shuffle(char answer_num[], int shuffle_number) {
	int i, j;
	char tmp;

	//配列の末尾を指定
	i = shuffle_number - 1;//　シャッフル用


	while (i > 0) {
		//シャッフル用の乱数
		j = rand() % (i + 1);

		//シャッフル
		tmp = answer_num[j];
		answer_num[j] = answer_num[i];
		answer_num[i] = tmp;


		i--;//シャッフル範囲がだんだん狭くなる
	}
}



//数字か文字か判別
//戻り値がintなのでint型関数を作る
int datatype(char input_string[], int len) {
	for (int i = 0; i < len; i++) {
		if (!isdigit(input_string[i])) {
			return 0;
		}
	}
	return 1;
}

//同じ数字がないか確認
int check_number(char input_string[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (input_string[i] == input_string[j]) {
				return 0;

			}


		}

	}
	return 1;
}












//数字入力   main関数で実行
void input_num(char input[], int num_size) {

	char input_string[100];
	printf("\nstart\n");
	
	

	while (1) {

		scanf("%s", &input_string);

		if (strlen(input_string) != num_size) {
			printf("%d桁じゃないです\n", num_size);
			continue;
		}


		if (!datatype(input_string, num_size)) {
			printf("数字じゃないのが入ってます...\n");
			continue;
		}

		if (!check_number(input_string, num_size)) {
			printf("桁に重複がありますやり直し...\n");
			continue;
		}

		//桁に重複なければループ抜けられる
		for (int i = 0; i < num_size; i++) {
			input[i] = input_string[i];
		}

		break;
	


	}



}



int Hit(char input[], char answer[], int num_size) {


	int count_hit = 0;

	for (int i = 0; i < num_size; i++) {
		for (int j = 0; j < num_size; j++) {
			if (answer[i] == input[j]) {

				if (i == j) {
					count_hit++;


				}


			}


		}



	}
	return count_hit;



}




//inputとanswerを比較して blowをカウント　mainで実行
int Blow(char input[], char answer[], int num_size) {
	int blow_count = 0;

	for (int i = 0; i < num_size;i++) {
		for (int j = 0; j < num_size; j++) {
			if (input[i] == answer[j]) {
				if (i != j) {
					blow_count++;
				}
			}

		}


	}

	return blow_count;
}




int main(void) {

	char answer_num[] = { '0','1','2','3','4','5','6','7','8','9' };
	char answer[NUM_SIZE];//正解格納用
	int shuffle_number = sizeof(answer_num) / sizeof(answer_num[0]);//　シャッフル用
	int rimit = 0;

	int hit_count, blow_count;
	srand((unsigned)time(NULL));

	//正解格納
	shuffle(answer_num, shuffle_number);
	for (int i = 0; i < NUM_SIZE;i++) {
		answer[i] = answer_num[i];
	}








	//ゲームループ
	do {

		char input[4];
		input_num(input, NUM_SIZE);


		hit_count = Hit(answer, input, NUM_SIZE);//
		blow_count = Blow(answer, input, NUM_SIZE);

		printf("%d HIT!! | %d BLOW!!\n", hit_count, blow_count);


		rimit++;
		/*
		if (rimit == 5) {
			printf("----GAMEOVER----");
			break;

		}
        */
	} while (hit_count < NUM_SIZE);//4桁揃わない間 


								   //答えが出たら公開								   
	printf("!!!! GAME_CLEAR !!!!\n");
	printf(" answer = [");
	for (int i = 0; i < NUM_SIZE; i++) {
		printf("%c", answer[i]);
	}
	printf("] \n");

	return 0;



}






/*
int main(void)
{
	int i, a[20];
	a[0] = 1;
	a[1] = 1;
	for(i = 2; i < 20; i++) {
		a[i] = a[i - 1] + a[i - 2];
		printf("第%2d項", i+1);
	}
	printf("\n");
	for(i = 2; i < 20; i++) {
		
		printf("%5d", a[i]);
		
	}
	   return 0;
}

*/

/*
int main(void) {
	int score[3][5];
	int i, j, rank[5];
	float m[5], n[5], q[3];
	float total_score;
	int p;

	
	for (i = 0;i < 5;i++) rank[i] = 1;

	for (i = 0; i < 3;i++) {
		
		m[i] = 0;
		printf("番号-------->",scanf("%d",&p));
		printf("国語-------->",scanf("%d",&score[i][0]));
		printf("数学-------->", scanf("%d", &score[i][1]));
		printf("社会-------->", scanf("%d", &score[i][2]));
		printf("理科-------->", scanf("%d", &score[i][3]));
		printf("英語-------->", scanf("%d", &score[i][4]));
	
		if (p ==0) {
			printf("---データの入力がありません\n  終了します----");

		}
		for (j = 0; j < 5;j++) {
			m[i] = m[i] + score[i][j];

		}	//m[i] += total_score / 3.0;
	}
	for (i = 0; i < 4;i++) {
		for (j = i + 1; j < 5;j++) {

			if (m[i] > m[j]) {
				rank[j]++;

			}
			if (m[i] < m[j]) {
				rank[i]++;

			}
		}

	}
	



	

		printf("番号   国語     数学      社会     英語  理科    個人合計   平均    順位\n");

		for (i = 0;i < 3; i++) {
		
			for (j = 0; j < 5;j++) {
				printf("       %3.1d", score[i][j]);

			}printf("     %7.1f     %7.1f      %d\n",m[i], m[i] / 5.0, rank[i]);

		}
		
		for (i = 0;i < 5;i++) {
			n[i] = 0;
			for (j = 0; j < 3;j++) {
				n[i] = n[i] + score[i][j];


			}
			printf("科目合計%7.1f科目平均%7.1f\n", n[i], n[i] / 3.0);
		}



	

	return 0;



}










*/










/*
int main(void){
char s[30]= {'T','h','e',' ','C',' ','P','r','o','g','r','a','m','i','n','g',' ','r','a','n','g','u','a','g','e'}; 

for(int i =0; i < 30;i++){
	printf("% c",s[i]);



	
}


return 0;
}
*/



























/*
void height_data(int student_year,float height[]){

	int one_year =0,three_year=0,
	two_year=0,not_found=0;//学年,学年データなし
    
	float  one_year_totalheight=0, //学年毎合計値
	two_year_totalheight=0,three_year_totalheight=0;

	float total_height=0;//合計
	
	for(int i =0; i <10;i++){
		printf("%d人目:学年を入力してください",i+1);
		scanf("%d",&student_year);
		printf("身長を入力してださい");
		printf("\n");
		scanf("%f",&height[i]);
	
		total_height+=height[i];
		

		if(student_year == 3){
				three_year++;             //学年人数カウント
				three_year_totalheight+=height[i];//学年別に振り分ける

			}else if(student_year==2){
				two_year++; 
				two_year_totalheight+=height[i];

			}else if(student_year==1){
				one_year++;
				one_year_totalheight+=height[i];
                
			}else if (student_year ==0){
				not_found++;

			}else if (student_year > 3){
				break;

			}

//		if(i == (sizeof(height[i])/sizeof(int))){
//			break; //要素の格納が終わったら表示
//			}
			
			
		}

  for(int i =0; i < 10;i++){


  }printf("全学年平均:%4.1f\n",total_height/10.0);
  printf("1学年:%d人平均:%4.1f\n",one_year,one_year_totalheight/ one_year);
  printf("2学年:%d人平均%4.1f\n",two_year,two_year_totalheight/two_year);
  printf("3学年:%d人平均%4.1f\n",three_year,three_year_totalheight/three_year);
  printf("学年不明%d",not_found);

  printf("\n");



}





int main(void){
	float height[10];
	int student_year;

	printf("学年別身長一覧\n");

    
	height_data(student_year,height);
	



	return 0;

}


*/


















































/*
void len(float n[] ){
	
	for(int i =0;i < 11;i++){
		
	
	}
	
	
	for(int i =0;i < 11;i++){
		printf("%2.1f|%1.8f\n",n[i],sqrt(n[i]));
	}


}






int main(void){
	//float n[11] ={3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0} ;
   
    printf(" X |    root       \n");
	printf("---+---------------\n");	



	



	return 0;



}


*/






































/*
int main(void){
	int  n[10][10];

	for(int i=0;i<10;i++){
		for(int j =0; j < 10; j++){
			n[i][j] = 0;
            n[0][0] =1;
            n[1][1] =1;
            n[2][2] =1;		   
            n[3][3] =1;		   
            n[4][4] =1;
            n[5][5] =1;		   
            n[6][6] =1;		   
            n[7][7] =1;		   
            n[8][8] =1;		   
            n[9][9] =1;		   




		}


	}

	for(int i=0;i<10;i++){
		for(int j =0; j < 10; j++){
			printf("%3d",n[i][j]);

		}
		printf("\n");


	}




*/








































/*
void total_data(float num[],float result){
int i;

for( i =0; i< 10;i++){
	printf("%d番目のデータ:",i+1);
	scanf("%f",&num[i]);   //入力

}

result=0;
for(i =0; i< 10; i++){
		
	result +=num[i]; 
}
	
for(i =0; i < 10; i++){

	}printf("合計%3.1f\n平均:%3.1f\n",result,result/10);//合計,平均出力




}


int main(void){
	int i, j;
	float num[10],result =0,temp;


  total_data(num,result);
//最大値,最小値をソートして出力

 for(i =0;i < 9;i++){
	for(j =i+1;j < 10; j++){
    if(num[i] < num[j]){
		temp = num[i];
		num[i] = num[j];
		num[j] = temp;
	}
	}
}printf("最大値:%3.1f\n最小値:%3.1f",num[0],num[9]);

	return 0;


}






*/


























/*
void calculator(float array[],float n){
	n=0;
	for(int i =0; i < 5;i++){
		n+=array[i];
	}printf("合計%3.1f\n平均%3.1f",n,n/5.0);
}

int main(void){
	float array[5]={10,30,50,70,90},n=0;

	calculator(array,n);

}
*/





































/*
int main(void){
	int matrix[5][6],i,j;

//代入
	for(i=0; i < 5; i++){
		for( j =0; j < 6; j++){
			matrix[i][j] = 8;

		}   

	}

//成分表示
    for( i =0; i < 5; i++ ){
		for( j =0;j < 6; j++){
			printf("%3d",matrix[i][j]);
       
	   }printf("\n");

	}

	return 0;



}



*/























/*

void calc_total(int height[],int total){
int i;
for( i =0; i< 10;i++){
	printf("%d人目:",i+1);
	scanf("%d",&height[i]);   //入力

}
	
for(i =0; i< 10; i++){
		total +=height[i]; 
}
	
for(i =0; i < 10; i++){

	}printf("合計%d\n平均:%d\n",total,total/10);//合計,平均出力




}


int main(void){
	int i, j,height[10],total=0,average=0,temp;


  calc_total(height,total);
//最大値,最小値をソートして出力

 for(i =0;i < 9;i++){
	for(j =i+1;j < 10; j++){
    if(height[i] < height[j]){
		temp = height[i];
		height[i] = height[j];
		height[j] = temp;
	}
	}
}printf("最大値:%d\n最小値:%d",height[0],height[9]);

	return 0;


}


*/






















/*
void calc(int n[]){
	printf("%d",n[0]+n[1]);
}
int main(void){
	int n[2] ={1000,2000};
	
	calc(n);
	
	return 0;


}
*/
































/*
if(score[i] > score[j]){
          rank[j]++;
          }
          if(rank[i] <rank[j]){
          rank[i] ++;

          }
*/



























/*
#include <stdio.h>                                                    

#include <stdio.h>
int main()
{
  int i, j,n,flag,count=0,result = 0,l;
  
   //判定フラグ //
 
 scanf("%d",&n);
  // 素数かどうかを判定 //
  
  for( i=2;i<=n;++i ) {
      flag= 0 ;
    
    for( j=2;j<i;++j ){
      if( i%j==0 ) {
         flag = 1;
        break;
      }
    }
     //判定結果を出力 
     if( flag==0){
      count++;

      printf(" %d:%d",i,count);
      printf("\n");

  }
  


  
  
  
}
return 0;


}
*/