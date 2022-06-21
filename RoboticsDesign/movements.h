//arrays of movements
//SPECIAL: hello, hand in front of mouth,     yes, no, head down sad, kermit, watch the birds, look away (scatto sinistra), looking for something, falling asleep, stay with open mouth for sometime, 
//random: shake hand
int hello[] = {11, 8, 7, 7, 7, 7, 7, 7, 7, 7, 12, 28, 60, 98, 117, 119, 89, 59, 86, 104, 70, 63, 104, 112, 104, 71, 40, 18, 4, 0};
int hello2[] = {0
,
10
,
20
,
30
,
40
,
50
,
60
,
70
,
80
,
90
,0
,
10
,
20
,
30
,
40
,
50
,
60
,
70
,
80
,
90
,0
,
10
,
20
,
30
,
40
,
50
,
60
,
70
,
80
,
90
,0,0,0};
int zero[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int yes[] = {106, 120, 145, 160, 151, 131, 125, 138, 145, 143, 132, 123, 132, 143, 145, 139, 133, 124, 117, 107, 95, 85, 75, 66, 63, 79, 90, 89, 85, 105, 103, 87, 79, 76, 70, 60, 44, 34, 28, 17, 12, 11};
int arraySize(int* arr[]){ //doesn't work
  return (int)(sizeof(arr) / sizeof(arr[0]));
}
int arraySizes[] = {(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0]))}; //sizes of arrays
int* movements[] = {hello,zero,zero,zero,
                    zero,yes,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,
                    hello,zero,zero,zero,}; //arrays pointers


//movements to randomize
/*
int*movements[]={};

int arraySize[2];*/
