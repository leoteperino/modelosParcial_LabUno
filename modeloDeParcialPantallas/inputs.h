int getString(char* string, int len);
int getInt(int* integer);
int validationInt(char num[]);
int getFloat(float * floating);
int validationFloat(char num[]);
int getTxt(char* txt, int len);
int validationOnlyLetter(char string[]);
int getAlphaNumeric(char* txt, int len);
int validationAlphaNumeric(char string[]);

/**Contempla solo un rango de numeros establecidos entre minimo y maximo. Solo numeros enteros*/
int getNumber(int* number, char* message, char* errorMessage, int min, int max);
/**Contempla solo un rango de numeros establecidos entre minimo y maximo. Numeros enteros o decimales*/
int getFloatNumber(float* floatNumber, char* message, char* errorMessage, int min, int max);
/**Contempla solo texto y espacios*/
int getName(char* name, int len, char* message, char* errorMessage);
/**Contempla texto, numeros y espacios*/
int getTxtAndNum(char* txt, int len, char* message, char* errorMessage);


/***Faltaria diseñar:
* getCuit
* getDni
* getMail
* getWeb
*getChar
*/
