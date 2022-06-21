//arrays of movements
//SPECIAL: hello, hand in front of mouth,     yes, no, head down sad, kermit, watch the birds, look away (scatto sinistra), looking for something, falling asleep, stay with open mouth for sometime, 
//random: shake hand
int hello[] = {0, 4, 21, 42, 67, 92, 114, 122, 104, 84, 80, 102, 114, 103, 83, 81, 100, 116, 116, 101, 82, 61, 36, 9, 0};
int lookbirdsno[] = {92, 102, 112, 120, 129, 132, 132, 132, 132, 130, 126, 118, 107, 93, 78, 68, 61, 56, 55, 55, 55, 58, 68, 79, 93, 109, 125, 137, 141, 144, 144, 144, 137, 122, 109, 97, 89};

int kermitside[] = {86, 86, 86, 86, 86, 86, 86, 86, 86, 86, 86, 86, 86, 85, 85, 83, 79,
       70, 57, 43, 29, 20, 11,  9,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,  26, 36, 48, 61, 71,
       80, 86, 93};
int kermitopen[] = {179, 158, 158, 158, 158, 155, 153, 153, 154, 154, 154, 154, 154,
       154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154,
       154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154,
       154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 156, 161, 170,
       175, 179};
       
int lookbirdsyes[] ={150, 144, 135, 120, 112, 109, 108, 109, 109, 109, 109, 109, 109,
       108, 108, 108, 109, 110, 108, 111, 109, 110, 110, 109, 110, 110,
       109, 108, 109, 114, 120, 129, 135, 139, 141, 145, 151};
int sad[] = {152, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 177, 172, 165, 163, 160, 156, 153, 155, 154, 154, 153, 154, 154, 153};       
int shyhandmouth[] = {0, 17, 76, 122, 159, 178, 179, 179, 

179, 179, 179, 179, 179, 

179, 179, 179, 179, 179, 

179, 179, 179, 179, 179, 

179, 179, 179, 179, 179, 179, 167, 147, 132, 117, 103, 88, 74, 60, 47, 32, 17, 3, 0};

int shyopenmouth[] = {179, 158, 158, 158, 158, 155, 153, 153, 154, 154, 154, 154, 154,
       154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154, 154,
       154, 154, 156, 161, 170, 175, 179, 179, 179, 179, 179, 179, 179, 
       179, 179, 179};

int zero[] = {-1};
int arraySize(int* arr[]){ //doesn't work
  return (int)(sizeof(arr) / sizeof(arr[0]));
}
// neckSide = 2, neckUp = 1, arm = 0;
int arraySizes[] = {(sizeof(lookbirdsno) / sizeof(lookbirdsno[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(sad) / sizeof(sad[0])),(sizeof(kermitopen) / sizeof(kermitopen[0])),(sizeof(shyhandmouth) / sizeof(shyhandmouth[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0])),(sizeof(hello) / sizeof(hello[0]))}; //sizes of arrays
int* movements[] = {lookbirdsno,lookbirdsno,lookbirdsyes,zero,
                    hello,zero,zero,zero,
                    zero,zero,sad,zero,
                    zero,kermitside,zero,kermitopen,
                    shyhandmouth,zero,zero,shyopenmouth}; //arrays pointers


//movements to randomize
/*
int*movements[]={};

int arraySize[2];*/
