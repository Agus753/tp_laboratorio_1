#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this ->size = 0;
    	this ->pFirstNode = NULL;
    }
    return this;
}

int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pSiguienteNodo = NULL;
	int len = ll_len(this);
	int i;

	if(this == NULL || nodeIndex < 0 || nodeIndex >= len)
	{
		pSiguienteNodo = NULL;
	}
	else
	{
		pSiguienteNodo = this->pFirstNode;
		for(i = 0; i < nodeIndex; i++)
		{
			pSiguienteNodo = pSiguienteNodo->pNextNode;
		}
	}
    return pSiguienteNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len;
    Node* pNuevoNodo;
    Node* pNodoAnterior;
    len = ll_len(this);

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= len)
	{
		pNuevoNodo = (Node*)malloc(sizeof(Node));

		if(pNuevoNodo != NULL)
		{
			pNuevoNodo->pElement = pElement;

			if(nodeIndex == 0)
			{
				pNuevoNodo->pNextNode = this->pFirstNode;
				this->pFirstNode = pNuevoNodo;
			}
			else
			{
				pNodoAnterior = getNode(this, nodeIndex-1);
				if(nodeIndex == len)
				{
					pNodoAnterior->pNextNode =pNuevoNodo;
					pNuevoNodo->pNextNode = NULL;
				}
				else
				{
					pNodoAnterior->pNextNode = pNuevoNodo;
				}
			}

			this->size++;
			returnAux = 0;
		}
	}
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);
    	addNode(this, len, pElement);
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux;
    Node* pNode;
    int len;
    len = ll_len(this);
    if(this == NULL || index < 0 || index > len)
    {
    	returnAux = NULL;
    }
    else
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
    		returnAux = pNode->pElement;
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int len;
    Node* pNode;
    len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement;
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len;
    Node* pNode;
    Node* pNodoAnterior;
    len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
    	pNode = getNode(this, index);
    	pNodoAnterior = getNode(this, index-1);
    	if(pNode != NULL)
    	{
    		if(index == len)
    		{
    			pNode ->pElement = NULL;
    			pNodoAnterior->pNextNode = NULL;
    		}
    		else
    		{
    			if(index == 0)
    			{
    				this->pFirstNode = pNode->pNextNode;
    			}
    			else
				{
					pNodoAnterior->pNextNode = pNode->pNextNode;
				}
    		}
    		free(pNode);
    		this->size--;

    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	int returnAux = -1;
	    int i;
	    if(this != NULL)
	    {
	    	for(i = ll_len(this)-1; i >= 0;i--)
	    	{
	    		ll_remove(this, i);
	    	}

	    	returnAux = 0;
	    }
	    return returnAux;

    /*int returnAux = -1;
    int i;
    if(this != NULL)
    {
    	for(i = 0; i < ll_len(this);i++)
    	{
    		ll_remove(this, i);
    	}

    	returnAux = 0;
    }
    return returnAux;*/
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* elementoIndex;
    int i;
    int len;
    len = ll_len(this);

    if(this != NULL)
    {
    	for(i = 0; i < len; i++)
    	{
    		elementoIndex = ll_get(this, i);
    		if(elementoIndex == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len;
    if(this != NULL)
    {
    	len = ll_len(this);
    	if(len == 0)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len;
    len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
    	addNode(this, index, pElement);
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	void* returnAux = NULL;
	int len;
	len = ll_len(this);
	if(this != NULL && index >= 0 && index < len)
	{
		returnAux = ll_get(this, index);
		if(returnAux != NULL)
		{
			ll_remove(this, index);
		}
	}
	return returnAux;

    /*void* returnAux = NULL;
    int len;
    len = ll_len(this);
    Node* pNodo;
    if(this != NULL && index >= 0 && index < len)
    {
    	pNodo = ll_get(this, index);
    	if(pNodo != NULL)
    	{
    		returnAux = pNodo;
    		ll_remove(this, index);
    	}
    }

    return returnAux;*/
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int indexElemento;
    if(this != NULL)
    {
    	indexElemento = ll_indexOf(this, pElement);
    	returnAux = 1;
    	if(indexElemento == -1)
    	{
    		returnAux = 0;
    	}
    	/*else
    	{
    		returnAux = 1;
    	}*/
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)//optimizado
{
    int returnAux = -1;
    int i;
    int len;
    len = ll_len(this);
    void* pElement;

    if(this != NULL && this2 != NULL)
	{
    	returnAux = 1;
		for(i = 0; i < len; i++)
		{
			pElement = ll_get(this2, i);
			if(ll_contains(this, pElement)== 0)
			{
				returnAux = 0;
				break;
			}
		}

    /*if(this != NULL && this2 != NULL)
    {
    	for(i = 0; i < len; i++)
    	{
    		pElement = ll_get(this, i);
    		if(ll_contains(this, pElement)== 1)
    		{
    			contador++;
    		}
    	}
    	if(contador == ll_len(this2))
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}*/
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)//optimizado
{
    LinkedList* cloneArray = NULL;

    void* pElemento;
    int i;
	int len;
	len = ll_len(this);

	if(this != NULL && from >= 0 && from < len && to >from && to <= len)
	{
		cloneArray = ll_newLinkedList();
		for(i = from; i < to; i++)
		{
			pElemento = ll_get(this, i);
			if(pElemento != NULL)
			{
				addNode(cloneArray, i, pElemento);
			}
		}
	}

   /* Node* pNodo;
    int i;
    int len;
    len = ll_len(this);

    if(this != NULL && from >= 0 && from < len && to >from && to <= len)
    {
    	cloneArray = ll_newLinkedList();
    	for(i = from; i < to; i++)
    	{
    		pNodo = getNode(this, i);
    		if(pNodo != NULL)
    		{
    			addNode(cloneArray, i, pNodo->pElement);
    		}
    	}
    }*/

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len;
    len = ll_len(this);
    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, len);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int len;
    len = ll_len(this);
    void* auxElement1;
    void* auxElement2;
    void* aux;
    int i;
    int j;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
    	for(i = 0; i < len-1; i++)
    	{
    		for(j = i+1; j < len; j++)
    		{
    			auxElement1 = ll_get(this, i);
    			auxElement2 = ll_get(this, j);

    			if((pFunc(auxElement1, auxElement2)==1 && order == 1) || (pFunc(auxElement1, auxElement2)==-1 && order == 0))
    			{
    				aux = auxElement1;
    				ll_set(this, i, auxElement2);
    				ll_set(this, j, aux);

    				returnAux = 0;
    			}
    		}
    	}
    }

    return returnAux;
}
