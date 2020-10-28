/*
 * entity_builder.c
 *
 *  Created on: 27 oct. 2020
 *      Author: emilianovera
 */



	/*Una sola vez
	new (1)
	newParametros (2)
	delete (3)
	*/

	/*Por cada campo
	get (4*)
	set (5*)
	isValid (6*)
	*/


	/* 1 */
	tipo* tipo_new()
	{
		return (tipo*)malloc(sizeof(tipo));
	}

	/* 2 */
	tipo* tipo_newParametros(tipoCampo1 campo1,tipoCampo2 campo2,...,tipoCampoN campoN)
	{
		tipo* this = tipo_new();
		if(this != NULL)
		{
			if( tipo_setCampo1(this,campo1) != -1 &&
				tipo_setCampo2(this,campo2) != -1 &&
				tipo_setCampoN(this,campoN) != -1 )
			{
				return this;
			}
		}
		return NULL;
	}

	/* 3 */
	void tipo_delete(tipo* this)
	{
		free(this);
	}


	/*x pantalla*/
	typedef struct
	{
		char tipoCampo[100];
		char nombreCampo[100];
	}Campo;


	Campo arrayCampos[50];

	char tipo[] = "Empleado";
	int cantidadCampos = 2;
	arrayCampos[0].tipoCampo = "char*";
	arrayCampos[0].nombreCampo = "apellido";
	arrayCampos[1].tipoCampo = "int";
	arrayCampos[1].nombreCampo = "altura";

	printf("%s* %s_new(){return (%s*)malloc(sizeof(%s));}",tipo,tipo,tipo,tipo);

	/* 4 */
	tipoCampo tipo_getCampo(tipo* this)
	{
		if(this!=NULL)
		{
			return this->campo;
		}
		return NULL;
	}

	/* 5 para todos*/
	int tipo_setCampo(tipo* this, tipoCampo campo)
	{
		int retorno = -1;
		if(this != NULL && isValidCampo(campo) == 1)
		{
			this->campo = campo;
			retorno = 0;
		}
		return retorno;
	}

	/* 5 para cadenas */
	int tipo_setCampo(tipo* this, tipoCampo campo)
	{
		int retorno = -1;
		if(this != NULL && isValidCampo(campo) == 1)
		{
			strnpcy(this->campo,campo,(int) sizeof(this->campo));
			retorno = 0;
		}
		return retorno;
	}

	/* 6 */
	int isValidCampo(tipoCampo campo)
	{
		return 1;
	}

	/* 6 */
	int isValidNombre(char* nombre)
	{
		return 1;
	}
