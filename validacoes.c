#include <stdio.h>

// essas validações não estão prontas---- em construção

int  valid_alfabetica(char letra){

    if ((letra >= 'a' && letra <= 'z') ||  (letra >='A' && letra <= 'Z')){
        return 1;
        
    }
  

    else{


        return 0;
        
   }
}

