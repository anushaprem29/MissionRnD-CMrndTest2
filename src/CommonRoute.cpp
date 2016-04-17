/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit 
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List .
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) .
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any 
number of times.
Output :
Return a Common Route String which covers maxiumum Islands 

Example 1 : 
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ" 
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation : 
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs 
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before 
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB 
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost ) 
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>

int len(char *s){
	int iter;
	for (iter = 0; s[iter] != NULL; iter++){
		iter++;
	}
	return iter;
}
void check(char *str, char *word,int arr[30][2], int start, int end, int *index){
	int iter, iter2=start, len1 = len(word);
	for (iter = 0; iter < len1; iter++){
		if (word[iter] == str[iter2] && iter2<=end){ iter2++;
		if (iter2 == end + 1){ 
			arr[*index][0] = end -start;
			arr[*index][1] = end +1;
			(*index)++;
			return; }
		}
		else{
			iter2 = start;
		}
		
	}
}

char * get_sub_string(char *str, int i, int j){
	int iter;
	if (str == NULL || i > j)	return NULL;
	char * sub = (char *)malloc(sizeof(char)*(j - i + 2));
	for (iter = i; iter <= j; iter++){
		if (str[iter] != '\0'){
			sub[iter - i] = str[iter];
		}
	}
	sub[iter - i] = '\0';
	return sub;
}

char * find_common_route(char * hacklist, char *codelist, int *cost){
	if(hacklist==NULL||codelist==NULL||cost==NULL)	return NULL;
	int iter1, iter2,iter3=0;
	int len1 = len(hacklist);
	int len2 = len(codelist);
	int arr[30][2];
	for (iter1 = 0; iter1 < len1; iter1++){
		for (iter2 = iter1 + 1; iter2 < len1; iter2++){
			check(hacklist, codelist,arr,iter1,iter2,&iter3);
		}
	}
	int start = 0, end = 0;
	int  max = arr[0][1] - arr[0][0];
	for (iter1 = 1; iter1 < 30; iter1++){
		if ((arr[iter1][1] - arr[iter1][0]) > max){
			max = arr[iter1][1] - arr[iter1][0];
			start = arr[iter1][0];
			end = arr[iter1][1] ;
		}
	}
	for (iter1 = 0; iter1 < 30; iter1++){
		if ((arr[iter1][1] - arr[iter1][0]) == max){
			*cost = 0;
			for (iter2 = arr[iter1][0]; iter2 <= arr[iter1][1]; iter2++){
				*cost += codelist[iter2];
			}
			return get_sub_string(codelist, start, end);
		}
	}
	return NULL;
}



