#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<math.h>
#include<time.h>
#include<ctime>
//function to generate random number between 0 to num
double random(double num){
	double x ; 
	x = ((double)rand()/(double)(RAND_MAX)) * num;
	return x ; 
}

bool is_inside_sine(double x , double y){
	double temp ; 
	temp = y - sin(x); 
	if(temp < 0){
		return true ; 
	}else{
		return false ; 
	}
}

//monte carlo integration serial code  
int main(){ 
	srand(time(0));  // seed
	int i=0 ; 
	bool check ; 
	int inside_count = 0 ; 
	int outside_count = 0 ; 
	double x ; 
	double y ;  
	double area ; 
	double rectangle_area = 3.14 ; 
	
	for(i=1;i<=10000000;i++){
		x = random(3.14); 
		y = random(1); //random position 
		check = is_inside_sine(x,y); 
		if(check == true){
			inside_count = inside_count + 1 ; 
		}else if(check == false){
			outside_count = outside_count + 1 ; 
		}
	}

//calulating area
area = rectangle_area * ((double)inside_count/(double)(outside_count + inside_count));
printf("Inside : %d , Outside : %d \n",inside_count , outside_count); 
printf("value of integration : %f \n",area);

	return 0 ; 
}

