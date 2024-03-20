#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 

static int db_render_output(void *data, int argc, char **argv, char **azColName){
   int i,ii,c,_counter;
   /* fprintf(stderr, "%s: ", (const char*)data); */
   
   printf("%s\n--------------------------\n", "Phonebook list:");  

   for(c = 0; c< argc; c++){          
      printf("%s\t\t",azColName[c]);      
   }
   printf("\n%s\n", "--------------------------");
   _counter =0 ;
   for(i = 0; i<argc; i++){
      for(ii = 0; ii<argc; ii++){    
         if(argv[_counter] == NULL) return 0;
         printf("%s\t",argv[_counter] ? argv[_counter] : "NULL");
         if(ii%2){
            printf("\n");            
         }
         _counter++;
         if(_counter>argc) return 0;
      }          
      
   }  
   
   printf("\n");
   return 0;
}

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   const char* data = "";

   /* Open SQLite database */
   rc = sqlite3_open("./db/phonebook.db", &db);
   
   if( rc ) {
      /* DB open error message */
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {

      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "SELECT name,mobile from phones";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, db_render_output, (void*)data, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "\n\nEnd of list\n");
   }
   sqlite3_close(db);
   return 0;
}