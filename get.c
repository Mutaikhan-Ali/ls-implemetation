#include "source.h"

t_opt* get_values(int ac,char**av)
{

    t_opt*opt = init_opt();

    int i = 1; // skip, the null ptr

    while(i < ac)
    {
        parse_args(opt, av[i]); // get arg values and parse them
        i++; // move to next
    }

    return opt;
}

int get_NumberOfFiles(char *path, int all)
{
    DIR* dir;
    struct dirent* entry;
    int size = 0;

    dir = opendir(path);

    while((entry = readdir(dir)) != NULL)
    {
        // skip hidden files
        if(!all && entry->d_name[0] == '.')
        {
            continue;
        }
        size += 1;
    }
    
    closedir(dir);

    return size;
}

int get_pathes(int ac,char**av)
{
    int l = 0;
    for(int i = 1;i<ac;i++)
    {
        if(!is_Command(av[i]))
        {
            l++;
        }
    }
    return l;
}


int get_numberOfSubDirs(char*path,int all)
{
    int l = 0;
    DIR*dir;
    struct dirent*entry;

    dir = opendir(path);
    
    while((entry = readdir(dir)) != NULL)
    {   
        if(entry->d_type & DT_DIR)
        {
            if(!all && entry->d_name[0] == '.')
            {
                continue;
            }
            
            if(my_strcmp(entry->d_name, ".") == 0 || my_strcmp(entry->d_name, "..") == 0)
            {
                continue;
            }
            l++;
        }
    }

    closedir(dir);
    return l;
}


// shoul be freed

void get_name_values(t_modifiedTime*m_files[], char*path, char* file_names[],int l)
{
    for(int i = 0;i<l;i++)
    {
        m_files[i]->name = (char*)(malloc(sizeof(char) * (my_strlen(file_names[i]) + 1)));
        my_strcpy(m_files[i]->name,file_names[i]);

        m_files[i]->path = (char*)(malloc(sizeof(char) * (my_strlen(file_names[i]) + my_strlen(path) + 2)));
        my_strcpy(m_files[i]->path,path);


        if(m_files[i]->path[my_strlen(m_files[i]->path) - 1] !='/')
        {
            my_strcat(m_files[i]->path,"/");
        }
        my_strcat(m_files[i]->path,file_names[i]);
        my_strcat(m_files[i]->path,"\0");

    }
}

void get_time_values(t_modifiedTime*m_files[], int l)
{
    for(int i =0;i < l;i++)
    {
        m_files[i]->timeValue = get_modifiedTimeOf(m_files[i]->path);
    }
}

long long get_modifiedTimeOf(char* path)
{
    long long timeValue = 0;
    struct stat st;

    stat(path,&st);

    timeValue = st.st_mtime;
    timeValue = timeValue * 1000;
    timeValue += st.st_mtim.tv_nsec / 1000000;

    return timeValue;
}