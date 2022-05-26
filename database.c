#include "basic.h"
#include "database.h"
#include "myDS.h"

Node* first_DB = NULL;
Node* last_DB = NULL;
int data_num;

//add the data into database
void Add_DB(Inform patient){
  Add(&first_DB, &last_DB, patient);
  data_num++;
}

//delete the data from database
void Delete_DB(Inform patient){
  Delete(first_DB, patient.name);
  data_num--;
}

//traverse the database
void Traverse(){
  Print_ALL(first_DB);
}

//search the database
void Search_DB(Inform patient){
  Search(first_DB, patient.name);
}

//sort the database by chart No.
void Sort_DB(char* type){
  InsertionSort(&first_DB);
}

//input the data from a file

void File_Input_DB(){
  FILE* fp = fopen("Input.txt", "r");
  Inform input;

  if(fp == NULL)
    fprintf(stderr, "Open file failed\n");
  else{
    while(fscanf(fp, "%s %d %f %s", input.name, &input.age, &input.weight, input.situation) != EOF)
      Add_DB(input);
  }

  fclose(fp);
}

//output the database into a file
void File_Output_DB(){
  FILE* fp = fopen("Patient information.txt", "w");
  
  if(fp == NULL)
    fprintf(stderr, "Open file failed\n");
  else{
    fprintf(fp, "Chart No.\tName\t\tAge\t\tWeight\t\tSituation\n");
    Node* cur = first_DB;
    while(cur != NULL){
      fprintf(fp, "%d\t\t%s\t\t%d\t\t%.2f\t\t%s\n", cur->field.number, cur->field.name, cur->field.age, cur->field.weight, cur->field.situation);
      cur = cur->next;
    }
    fprintf(stderr, "Successful\n");
  }

  fclose(fp);
}