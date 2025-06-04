#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient{
    char name[50] ;
    char gender ;
    long dateOfAdmission ;
    long dateOfBirth ;
    char illness[50] ;
    char cityOfPatient[20] ;
    char bloodType[5] ;
    int recoveringPatient;

    struct Patient *NEXT;
};

struct string{
    char statment[50];
    struct string* next;
};

struct bucket{
    char name[50];
    struct bucket* next;
};

void readFile (struct Patient* L,struct string* S);//done
void addString(struct string* S,char s[]);//done
void deleteStrings(struct string* S);//done
struct Patient* MakeEmpty(struct Patient* L);//done
int isEmpty(struct Patient* L);//done
int isLast(struct Patient* L,struct Patient* p);//done
void deleteLinkedListOfPatients(struct string* L);//done
void radixSort(struct string* S ,struct bucket* array[]);//done
void addPatient(struct Patient* L ,char name[],char gender,long dateOfAdmission,long dateOfBirth,char illness[],char cityOfPatient[],char bloodType[]);//done
struct Patient* searchForPatient(char name[] ,struct Patient* L);//done
struct Patient* searchForPatient2(long dateOfBirth ,struct Patient* L);//done
void deletePatient(char name[],struct Patient* L);//done
void updateInformationPatient(struct Patient* L ,char name[],char gender,long dateOfAdmission,long dateOfBirth,char illness[],char cityOfPatient[],char bloodType[]);//done
void printAllPatients(struct Patient* L);//done
void printIllness(struct Patient* L);//done
void printCity(struct Patient* L);//done
void printRecoveringPatients(struct Patient* L);//done
void writeOnFile(struct Patient* L);//done
void writeOnXmlFile(struct Patient* L);//done

int main()
{

    //create patient linked list
    struct Patient* L = NULL;
    L = MakeEmpty(L);

    //create string linked list
    struct string* S = NULL;
    S = (struct string*)malloc(sizeof(struct string));


    int option = 1;
    while(option > 0 && option < 10){
        printf("welcome in AlAmal hospital,choose one option below\n");
        printf("1.to read the data of the patients from	the file.\n");
        printf("2.to sort the patients in terms of their names\n");
        printf("3.to add new patient\n");//done
        printf("4.to update patient's information\n");
        printf("5.to delete patient\n");
        printf("6.to search for patient\n");
        printf("7.to list patients\n");
        printf("8.to export medical report\n");
        printf("9.Exit and stored the information to the file\n");

        scanf("%d",&option);

        switch(option){
            case 1:readFile(L,S);//call the function of read file
                    break;
            case 2:{

                struct Patient* p;
                p = L;
                //add the names to the string linked list to sorted it
                while(p->NEXT != NULL){
                    addString(S,p->NEXT->name);
                    p = p->NEXT;
                }

                //to initialization the contents of array
                struct bucket* array[256];
                for(int i =0;i<256;i++){

                    array[i] = (struct bucket*)malloc(sizeof(struct bucket));
                }

                radixSort(S,array);

                struct Patient* temp ,*r;
                r = (struct Patient*)malloc(sizeof(struct Patient));
                r->NEXT = L->NEXT;
                L->NEXT = NULL;
                struct string* s;
                s = S;

                //after sorted names ,we search for patient and add sorted patient to the linked list
                while(s->next != NULL){
                    temp = searchForPatient(s->next->statment,r);
                    addPatient(L,temp->name,temp->gender,temp->dateOfAdmission,temp->dateOfBirth,temp->illness,temp->cityOfPatient,temp->bloodType);
                    s = s->next;
                }
                deleteStrings(S); //to free the content of S
                deleteLinkedListOfPatients(r); //to free the content of r

                printf("the sorting operation is success\nThe new sorting shown below:\n");
                printAllPatients(L);
                }
                    break;
            case 3:{
                //read the name for new patient
                printf("Enter the name of patient\n");
                char name[50];
                fflush(stdin);
                gets(name);

                //read the gender of the new patient
                printf("Enter the gender(M/F) of patient \n");
                char gender ;
                scanf("%c",&gender);

                //check if the user entered the gender correctly
                while(gender!='M' && gender!='F' ){
                    printf("the gender is wrong\n");
                    printf("please enter correct gender\n");

                    scanf(" %c",&gender);
                }

                 //read date of admission for the new patient
                 printf("Enter the date of admission for patient (example : 01012000)\n");
                 long dateOfAdmission;
                 scanf("%d",&dateOfAdmission);

                 //read date of birth for the new patient
                 printf("Enter the date of birth for patient(example : 01012000)\n");
                 long dateOfBirth;
                 scanf("%d",&dateOfBirth);

                 //read the illness for the new patient
                 printf("Enter the illness of the patient\n");
                 char illness[50];
                 fflush(stdin);
                 gets(illness);

                 //read the city for the new patient
                 printf("Enter the city of the patient\n");
                 char city[20];
                 fflush(stdin);
                 gets(city);

                 //read the blood type for the new patient
                 printf("Enter the blood type of the patient(example : O+)\n");
                 char bloodType[5];
                 fflush(stdin);
                 gets(bloodType);

                //call the function to add the patient
                addPatient(L,name,gender,dateOfAdmission,dateOfBirth,illness,city,bloodType);
            }
                    break;
            case 4:{
                //read the name for the patient
                printf("Enter the name of patient\n");
                char name[50];
                fflush(stdin);
                gets(name);

                //read the gender of the patient
                printf("Enter the gender(M/F) of patient \n");
                char gender;
                scanf(" %c",&gender);

                //check if the user entered the gender correctly
                while(gender!='M' && gender!='F' ){
                    printf("the gender is wrong\n");
                    printf("please enter correct gender\n");

                    scanf(" %c",&gender);
                }

                 //read date of admission for the patient
                 printf("Enter the date of admission for patient (example : 01012000)\n");
                 long dateOfAdmission;
                 scanf("%d",&dateOfAdmission);

                 //read date of birth for the patient
                 printf("Enter the date of birth for patient(example : 01012000)\n");
                 long dateOfBirth;
                 scanf("%d",&dateOfBirth);

                 //read the illness for the patient
                 printf("Enter the illness of the patient\n");
                 char illness[50];
                 fflush(stdin);
                 gets(illness);

                 //read the city for the patient
                 printf("Enter the city of the patient\n");
                 char city[20];
                 fflush(stdin);
                 gets(city);

                 //read the blood type for the patient
                 printf("Enter the blood type of the patient(example : O+)\n");
                 char bloodType[5];
                 fflush(stdin);
                 gets(bloodType);

                //call the function to update the information for patient
                updateInformationPatient(L,name,gender,dateOfAdmission,dateOfBirth,illness,city,bloodType);

            }
                    break;
            case 5:{
                //read the name for the patient
                printf("Enter the name of patient\n");
                char name[50];
                fflush(stdin);
                gets(name);

                deletePatient(name,L);
            }
                    break;
            case 6:{
                printf("\tEnter 0 to search in terms of name\n");
                printf("\tEnter 1 to search in terms of date of birth\n");
                int x;
                scanf("%d",&x);

                struct Patient* p;

                if(x == 0){
                    //read the name for the patient
                    printf("Enter the name of patient\n");
                    char name[50];
                    fflush(stdin);
                    gets(name);
                    p = searchForPatient(name,L);

                    if(p == NULL)
                        printf("the patient does not exist\n");
                    else{
                        if(p->recoveringPatient == 0)
                            printf("the patient is exist\n");
                        else
                            printf("the patient is recover\n");
                    }
                }
                else if(x == 1){
                    //read the date of birth for the patient
                    printf("Enter the date of birth for the patient\n");
                    long dateOfBirth;
                    scanf("%d",&dateOfBirth);
                    p = searchForPatient2(dateOfBirth,L);

                    if(p == NULL)
                        printf("the patient does not exist\n");
                    else{
                        if(p->recoveringPatient == 0)
                            printf("the patient is exist\n");
                        else
                            printf("the patient is recover\n");
                    }
                }
                else
                    printf("the number is wrong\n");

            }
                    break;
            case 7:{
                printf("\tEnter 1 to list all patients\n");
                printf("\tEnter 2 to list cities for all patients\n");
                printf("\tEnter 3 to list illness for all patients\n");
                printf("\tEnter 4 to list recovering patients\n");
                int x;
                scanf("%d",&x);

                if(x == 1)
                    printAllPatients(L);
                else if(x == 2)
                    printCity(L);
                else if(x == 3)
                    printIllness(L);
                else if(x == 4)
                    printRecoveringPatients(L);
                else
                    printf("the number is wrong\n");

            }
                    break;
            case 8:{
                writeOnXmlFile(L);
            }
                    break;
            case 9:{
                writeOnFile(L);
                exit(0);
            }
                    break;
        }
        if(option > 0 && option < 10)
            printf("");
        else
            printf("ERROR!!!!!!, please enter (1 - 9 )\n");
    }

    return 0;
}
//read the patients from the file
void readFile (struct Patient* L,struct string* S){
    FILE* in;
    in =fopen("patients.txt","r");

    if(in == NULL){
        printf("the file does not exist");
        exit(0);
    }

    char c[40];

    //read the information from the file and store it in the string linked list
    while(fscanf(in,"%[^#,\n]%*c",c) != EOF){
        addString(S,c);
    }


    char name[50] ;
    long dateOfAdmission;
    long dateOfBirth;
    char gender;
    char illness[50];
    char city[20];
    char bloodType[5];

    int counter = 0;
    struct string* p = S;

    //move the information from string linked list to the variables
    //then add Patients contain the information to the patient linked list
    while(p->next != NULL){
        if(counter == 0){
            strcpy(name,p->next->statment);
        }
        else if(counter == 1){
            gender = (p->next->statment)[0];
        }
        else if(counter == 2){
            dateOfAdmission = atoi(p->next->statment); //casting from string to long
        }
        else if(counter == 3){
            dateOfBirth = atoi(p->next->statment);//casting from string to long
        }
        else if(counter == 4){
            strcpy(illness,p->next->statment);
        }
        else if(counter == 5){
            strcpy(city,p->next->statment);
        }
        else if(counter == 6){
            strcpy(bloodType,p->next->statment);
            counter = -1;
            addPatient(L,name,gender,dateOfAdmission,dateOfBirth,illness,city,bloodType);//call the function add patient and used the information stored in the variable
        }
       p = p->next; //let p pointer to the next node
       ++counter;

    }

    fclose(in);
    deleteStrings(S);//delete the content of the linked list S
    printf("the read operation is success\n");
}
//add string to the string link list
void addString(struct string* S ,char new_data[]){

    struct string* temp,*p;
    temp = (struct string*)malloc(sizeof(struct string));
    p = (struct string*)malloc(sizeof(struct string));
    p = S;

    //let p pointer on the last patient
    while(p->next != NULL){
        p = p->next;
    }

    strcpy(temp->statment,new_data);

    temp -> next = NULL;
    p -> next = temp;
}
//to delete the list of strings
void deleteStrings(struct string* S){
    struct string* p;
    struct string* temp;

    p = S->next;
    S->next = NULL;

    //to move from node to node and free it
    while (p != NULL){
        temp = p->next;
        free(p);
        p = temp;
    }
}
//create linked list
struct Patient* MakeEmpty(struct Patient* L){
    if(L != NULL){
        deleteLinkedListOfPatients( L );
    }

    L = (struct Patient*)malloc(sizeof(struct Patient));

    if(L == NULL)
        printf("Out of memory!\n");

    L->NEXT = NULL;
    return L;
}
//check if the linked list is empty
int isEmpty(struct Patient* L){
    return (L->NEXT == NULL);
}
//check if the node is the last node
int isLast(struct Patient* L,struct Patient* p){
    return (p->NEXT == NULL);
}
//to delete the linked list of patients
void deleteLinkedListOfPatients(struct string* L){
    struct string* p;
    struct string* temp;

    p = L->next;
    L->next = NULL;

    //to move from node to node and free it
    while (p != NULL){
        temp = p->next;
        free(p);
        p = temp;
    }
}
//to sorting set of strings by radix sort
void radixSort(struct string* S ,struct bucket* array[]){
    struct string* P;
    P = S->next;
    int maximum_char = 0;
    int j;
    //to find the big number of characters
    while(P!= NULL){
        for (j = 0; P->statment[j] != '\0'; ++j);//count the number of characters in the string

        if(j > maximum_char)
            maximum_char = j;

        P = P->next;
    }

    //to make all nodes pointer on NULL
     for(int y =0 ;y <256 ;y++){
            array[y]->next = NULL;
     }

    struct string* p ;
    p = S->next;
    struct bucket* z;
    struct bucket* q;


    int i;
    int counter = 1;

    //this loop to make the iterations //to move from char to char in the strings
    for(int x =0 ; x < maximum_char ;x++){
        p = S->next;
        while(p!= NULL){//to move from name to name
            for (i = 0; p->statment[i] != '\0'; ++i);//count the number of characters in the string

            if((i-counter) >= 0 ){
            z = array[(int)(p->statment)[i-counter]];

            //to move from backet to backet
            while(z->next != NULL){
                z = z->next;
            }
            z->next = (struct bucket*)malloc(sizeof(struct bucket));
            strcpy(z->next->name , p->statment);

            }
            else {
            z = array[0];

            //to move from backet to backet
            while(z->next != NULL){
                z = z->next;
            }
            z->next = (struct bucket*)malloc(sizeof(struct bucket));
            strcpy(z->next->name , p->statment);
            }

            p = p->next;
        }

        S->next = NULL;

        //move the content of array to string linked list
        for(int y =0 ;y <256 ;y++){
            q = array[y]->next;

            while(q != NULL){
                addString(S,q->name);
                q = q->next;
            }
        }

        //to remove the contents of the array
        for(int y =0 ;y <256 ;y++){
            array[y]->next = NULL;
        }

        counter++;//to move into the next character in the strings
    }

}
//add patient to the linked list
void addPatient(struct Patient* L ,char name[],char gender,long dateOfAdmission,long dateOfBirth,char illness[],char cityOfPatient[],char bloodType[]){

    struct Patient* temp,*p;
    temp = (struct Patient*)malloc(sizeof(struct Patient));
    p = (struct Patient*)malloc(sizeof(struct Patient));
    p = L;

    //let p pointer on the last patient
    while(p->NEXT != NULL){
        p = p->NEXT;
    }

    //fill the information for patient
    strcpy(temp->name, name);
    temp -> gender = gender;
    temp->dateOfAdmission = dateOfAdmission;
    temp -> dateOfBirth = dateOfBirth;
    strcpy(temp -> illness , illness);
    strcpy(temp -> cityOfPatient,cityOfPatient);
    strcpy(temp -> bloodType, bloodType);
    temp->recoveringPatient = 0;//the patient is not recover

    temp -> NEXT = NULL;
    p -> NEXT = temp;

}
//search for patient by name
struct Patient* searchForPatient(char name[] ,struct Patient* L){

    struct Patient* p;
    p = L->NEXT;

    //check if the entered name same as the patient name
    while(p != NULL && strcmp(p->name,name) != 0){
    p = p->NEXT;
    }

    return p;

};

//search for patient by date of birth
struct Patient* searchForPatient2(long dateOfBirth ,struct Patient* L){

    struct Patient* p;
    p = L->NEXT;

    //check if the entered date of birth same as the patient date of birth
    while(p != NULL && p->dateOfBirth != dateOfBirth){
    p = p->NEXT;
    }

    return p;

};
//to make the patient is recover patient
void deletePatient(char name[],struct Patient* L){

    struct Patient* p;
    p = searchForPatient(name,L);

    if(p == NULL){
        printf("the patient does not exist\n");
        return;
    }

    if(p != NULL){
        p->recoveringPatient = 1;//the patient is recover
        printf("the patient %s is recover\n",p->name);
    }

}

//to update the information of patient
void updateInformationPatient(struct Patient* L ,char name[],char gender,long dateOfAdmission,long dateOfBirth,char illness[],char cityOfPatient[],char bloodType[]){
    struct Patient* p;
    p = searchForPatient(name,L);

    if(p == NULL){
        printf("the patient does not exist\n");
        return;
    }


    //update the information of patient
    strcpy(p->cityOfPatient ,cityOfPatient);
    strcpy(p->bloodType,bloodType);
    strcpy(p->illness,illness);
    p->dateOfBirth = dateOfBirth;
    p->dateOfAdmission = dateOfAdmission;
    p->gender = gender;
    strcpy(p->name,name);

    printf("the update is success\n");

}
//print the name of all patients
void printAllPatients(struct Patient* L){
    struct Patient* p;
    p = L;

    if(isEmpty(L))
        printf("the list is empty\n");
    else
    {
        do{
            p = p->NEXT;

            //don't print the recovering patient
            if(p->recoveringPatient == 0)
            printf("%s\n",p->name);
        }while(!isLast(L,p));

        printf("\n");

    }
}
//print the name of the patients and their illness
void printIllness(struct Patient* L){
    struct Patient* p;
    p = L;

    if(isEmpty(L))
        printf("the list is empty\n");
    else
    {
        do{
            p = p->NEXT;

            //don't print the recovering patient
            if(p->recoveringPatient == 0)
            printf("name:%s\t illness:%s\n",p->name,p->illness);
        }while(!isLast(L,p));

        printf("\n");

    }
}

//print the name of the patients and their cities
void printCity(struct Patient* L){
    struct Patient* p;
    p = L;

    if(isEmpty(L))
        printf("the list is empty\n");
    else
    {
        do{

            p = p->NEXT;

            //don't print the recovering patient
            if(p->recoveringPatient == 0)
            printf("name:%s\t City:%s\n",p->name,p->cityOfPatient);
        }while(!isLast(L,p));

        printf("\n");

    }
}
//print the name of recovering patients
void printRecoveringPatients(struct Patient* L){
    struct Patient* p;
    p = L;

    if(isEmpty(L))
        printf("the list is empty\n");
    else
    {
        do{
            p = p->NEXT;

            //print the recovering patient
            if(p->recoveringPatient == 1)
            printf("%s\n",p->name);
        }while(!isLast(L,p));

        printf("\n");

    }
}
//write on the file
void writeOnFile(struct Patient* L){
    FILE* out;
    out = fopen("output.txt","w");

    struct Patient* p;
    p = L->NEXT ;

    //while loop to make p move from node to node and print the information of node on the file
    while(p != NULL){
        fprintf(out,"%s#%c#%d#%d#%s#%s#%s\n",p->name,p->gender,p->dateOfAdmission,p->dateOfBirth,p->illness,p->cityOfPatient,p->bloodType);
        p = p->NEXT;
    }
    printf("the write on file is success\n");
    fclose(out);
}
//write on xml file
void writeOnXmlFile(struct Patient* L){
    FILE* out;
    out = fopen("Report.xml","w");

    struct Patient* p ;
    p = L;

    //to move from patient to patient
    while(p->NEXT != NULL){
        //ptint on xml file
        fprintf(out,"<patient>\n");
        fprintf(out,"\t<Name>%s</Name>\n",p->NEXT->name);
        fprintf(out,"\t<gender>%c</gender>\n",p->NEXT->gender);
        fprintf(out,"\t<admissionDate> value ='%d'/>\n",p->NEXT->dateOfAdmission);
        fprintf(out,"\t<dateOfBirth> value ='%d'/>\n",p->NEXT->dateOfBirth);
        fprintf(out,"\t<diagnosis>%s</diagnosis>\n",p->NEXT->illness);
        fprintf(out,"\t<city>%s</city>\n",p->NEXT->cityOfPatient);
        fprintf(out,"\t<bloodType>%s</bloodType>\n",p->NEXT->bloodType);
        fprintf(out,"</patient>\n");
        p = p->NEXT;
    }
    printf("the print operation is success\n");
    fclose(out);
}
