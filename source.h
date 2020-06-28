#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <limits.h>
#include <dirent.h>

typedef struct s_opt
{
    int ls; // as default
    int ls_a;
    int ls_R;
    int ls_err;
    int ls_t; 
    char* path;
} t_opt;




typedef struct s_modifiedTime
{
    char* name;
    char* path;
    long long timeValue;

}t_modifiedTime;


// string
size_t my_strlen(char*a);
int my_strcmp(char *a, char *b);
char* my_strcpy(char*a,char*b);
char*  my_strcat(char *dest, char *src);
// initializes
t_opt* init_opt();
void multile_output(t_opt*opt,char*arr_pathes[],int path_number);
void init_struct(t_modifiedTime* modified[], int l);
void init_values(char*path, t_modifiedTime* modified[], char*file_names[],int l);
void print_result_for_pathes(t_opt*opt,int ac,char**av);
void print_resultFOR_ONE_PATH(t_opt* opt);
// parsing
void parse_args(t_opt*opt, char* arg);
void init_t_values(t_modifiedTime*files[],int l);
char** init_pathes(t_opt*opt,int ac,char**av);
// printing 
int print_error(t_opt*opt);

// gets
int get_pathes(int ac,char**av);
t_opt* get_values(int ac,char**av);
char*get_current_path();
void get_time_values(t_modifiedTime*m_files[], int l);
int get_NumberOfFiles(char*path, int all);
long long  get_modifiedTime(char*name,char*path);
void get_name_values(t_modifiedTime*m_files[], char*path, char* file_names[],int l);
long long get_modifiedTimeOf(char* path);
int get_numberOfSubDirs(char*path,int all);
void set_path_values(int ac,char**av,char*arr[]);
// is it ...

int is_Command(char* arg);
int is_a(char a);
int is_R(char R);
int is_t(char t);
int is_Exist(char*path);
int is_Exist_File(char*path);
// set 

void set_flags(t_opt *opt, char *arg);
void set_path(t_opt* opt,char* arg);
void set_flag(t_opt *opt, char arg);
void fill_arr(char*path, char*file_names[],int all);
void fill_subDirs(char*path,char**file_names,int all);
int print_file(t_opt*opt);
// myls
int myls(int err,char*path,int all, int time);
int myls_R(t_opt*opt,char*path,int all,int time);
void search_recursievly_files(t_opt*opt,char*path,int all,int time);
void free_string(char*file_names[],int l);
// sort
void time_sort(t_modifiedTime* modified[],char*file_names[], int l);
void sort_alphabetical(char*file_names[], int l);
void sort_byTime(char*path,char*file_names[],int l);
void sort(char*file_names[],char*path,int l,int time);
void swap(char**a,char**b);
void output_error(char*opt);
void output(char*file_names[],int l);
void swap_structures(t_modifiedTime **d1, t_modifiedTime **d2);
void swap_strings(char**a,char**b);
void lexico_sort(char*file_names[],int l);
void sort_t(t_modifiedTime* m_files[],int l);
void make_path(char*path,char*sub_path,char*entry);
void print_pathName(char*path);
void set_dirNames(char*path, char*dir_names[], int l,int all);