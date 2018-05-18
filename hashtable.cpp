
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct hash *hashTable = NULL;
struct node{
	char * key;
	char * value;
	struct node *next;
};

struct hash{
	struct node *head;
	int count;
};
hash * hashtable = (hash*)calloc(10,sizeof(hash));

struct node * createnode(char* key, char* value)
{
	struct node *newnode = (node*)malloc(sizeof(node));
	newnode->key = key;
	newnode->value = value;
	newnode->next = NULL;
	return newnode;
}
void insert(char *key, char *value,int count)
{
	int len = 0;
	len = strlen(key);
	int hashindex = len % count;
	struct node *newnode = createnode(key, value);
	if (hashtable[hashindex].head==NULL)
	{
		hashtable[hashindex].head = newnode;
		hashtable[hashindex].count++;
	}
	else
	{
		newnode->next = hashtable[hashindex].head;
		hashtable[hashindex].head = newnode;
		hashtable[hashindex].count++;
		return;
	}

}
void get(char* key,int count)
{
	int len = strlen(key);
	int hashindex = len%count;
	struct node * mynode = hashtable[hashindex].head;
	while (mynode != NULL)
	{
		if (mynode->key == key)
		{
			printf("key=%s\n", mynode->key);
			printf("value=%s", mynode->value);
			break;
		}
		else
		{
			mynode = mynode->next;
		}
	}
}