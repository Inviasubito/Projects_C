#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#define INPUT_FILENAME "input.txt"
#define MAX_VEHICLES 512

#define STRTOK_KEY " "
#define MEMORY_ALLOC_ERROR "Errore di memoria.\n"

typedef struct {
    int autonomy;
} Auto;

typedef struct {
    int distance;
    int num_vehicles;
    Auto* vehicles;
} ServiceStation;

ServiceStation* stations = NULL;
int stationsLength;

void mallocError(int);

void readInput();
void readInputCase(const char*);

int addServiceStation(ServiceStation);
int removeStations(int);
int addAuto(ServiceStation*, Auto);
int rmAuto(ServiceStation*, int);
ServiceStation* getStation(int);
Auto* getAuto(ServiceStation*, int);
int getStationIndex(int);
int getAutoIndex(ServiceStation*, int);

void addStationsFromString(const char*);
void addAutoFromString(const char*);
void removeStationsFromString(const char*);
void removeAutoFromString(const char*);

void calculateTripFromString(const char*);
int calculateTrip(int, int);
int getMaxAutonomy(int);

int main()
{
    stationsLength = 0;
   
    readInput();

    //printf("\nPremi un tasto per continuare.");
    //_getch();

    //

    for (int i = 0; i < stationsLength; ++i)
        free(stations[i].vehicles);
    free(stations);

    return 0;
}

void mallocError(int exitCode)
{
    printf(MEMORY_ALLOC_ERROR);

    if (exitCode >= 0)
        exit(exitCode);
}

void initializeAuto(int s_index)
{
    for (int i = 0; i < MAX_VEHICLES; i++)
        stations[s_index].vehicles[i].autonomy = -1;
}

void readInput()
{
    FILE* f = fopen(INPUT_FILENAME, "r+t");

    if (!f)
        printf("Impossibile aprire il file: %s.\n", INPUT_FILENAME);
    else
    {
        int i = 0;
        size_t size = 512;
        size_t len = 0;
        char* s = malloc(size);
        int c;
        int err = 0;

        //while (!err && (c = getchar_unlocked()) != EOF)
        while ((c = fgetc(f)) != EOF)
        {
            //sto superando il limite di stringa
            if (len == size - 1)
            {
                size *= 2;
                char* tmp = realloc(s, size);

                if (tmp == NULL)
                {
                    mallocError(-1);
                    free(s);
                    err = 1;
                }
                else
                    s = tmp;
            }

            if (s != NULL)
            {
                if (!err && c == '\n')
                {
                    s[len] = '\0';
                    printf("%d. ", ++i);
                    readInputCase(s);
                    len = 0;
                }
                else
                    s[len++] = c;
            }
        }

        free(s);
        fclose(f);
    }
}

void readInputCase(const char* s)
{
    if(s[9] == 's') //aggiungi-stazione
        addStationsFromString(s);
    else if (s[0] == 'd') //demolisci-stazione
        removeStationsFromString(s);
    else if (s[9] == 'a') //aggiungi-auto
        addAutoFromString(s);
    else if (s[0] == 'r') //rottama-auto
        removeAutoFromString(s);
    else if (s[0] == 'p') //pianifica-percorso
        calculateTripFromString(s);
    else
        printf("La funzione richiesta '%s' non risulta disponibile.\n", s);
}

#pragma region ManipulateStrings

void addStationsFromString(const char* s)
{
    ServiceStation st = { 0, 0, NULL };
    int st_index = -1;
    int arg_c = 0;

    char* temp = _strdup(s);
    char* token = strtok(temp, STRTOK_KEY);

    while (arg_c >= 0 && token != NULL)
    {
        arg_c++;
        if (arg_c > 1)
        {
            int value = atoi(token);

            if (arg_c == 2)
            {
                if (getStationIndex(value) != -1)
                    arg_c = -1;
                st.distance = value;
            }
            else if (arg_c == 3)
            {
                st_index = addServiceStation(st);
                if (st_index == -1)
                    arg_c = -1;
            }
            else
            {
                Auto a = { value };
                if (addAuto(&stations[st_index], a) == -1)
                    arg_c = -1;
            }
        }
        token = strtok(NULL, STRTOK_KEY);
    }

    free(temp);

    if (arg_c == -1)
        printf("non aggiunta\n");
    else
        printf("aggiunta\n");
}

void addAutoFromString(const char* s)
{
    ServiceStation* st = NULL;
    Auto a = { 0 };
    int arg_c = 0;

    char* temp = _strdup(s);
    char* token = strtok(temp, STRTOK_KEY);

    while (arg_c >= 0 && token != NULL)
    {
        arg_c++;
        if (arg_c > 1)
        {
            int value = atoi(token);

            if (arg_c == 2)
            {
                st = getStation(value);
                if (st == NULL)
                    arg_c = -1;
            }
            else
            {
                a.autonomy = value;
                if (addAuto(st, a) == -1)
                    arg_c = -1;
            }
        }
        token = strtok(NULL, STRTOK_KEY);
    }

    free(temp);

    if (arg_c == -1)
        printf("non aggiunta\n");
    else
        printf("aggiunta\n");
}

void removeStationsFromString(const char* s)
{
    int arg_c = 0;

    char* temp = _strdup(s);
    char* token = strtok(temp, STRTOK_KEY);

    while (arg_c >= 0 && token != NULL)
    {
        arg_c++;
        if (arg_c > 1)
        {
            int value = atoi(token);

            if (arg_c == 2)
                arg_c = removeStations(value);
        }
        token = strtok(NULL, STRTOK_KEY);
    }

    free(temp);
    
    if (arg_c == -1)
        printf("non demolita\n");
    else
        printf("demolita\n");
}

void removeAutoFromString(const char* s)
{
    ServiceStation* st = NULL;
    int arg_c = 0;

    char* temp = _strdup(s);
    char* token = strtok(temp, STRTOK_KEY);

    while (arg_c >= 0 && token != NULL)
    {
        arg_c++;
        if (arg_c > 1)
        {
            int value = atoi(token);

            if (arg_c == 2)
            {
                st = getStation(value);
                if (st == NULL)
                    arg_c = -1;
            }
            else
                arg_c = rmAuto(st, value);
        }
        token = strtok(NULL, STRTOK_KEY);
    }

    free(temp);

    if (arg_c == -1)
        printf("non rottamata\n");
    else
        printf("rottamata\n");
}

void calculateTripFromString(const char* s)
{
    int arg_c = 0;

    char* temp = _strdup(s);
    char* token = strtok(temp, STRTOK_KEY);
    int start = -1;

    while (arg_c >= 0 && token != NULL)
    {
        arg_c++;
        if (arg_c > 1)
        {
            int value = atoi(token);

            if (arg_c == 2)
                start = value;
            else
            {
                if (start != value)
                    arg_c = calculateTrip(start, value);
                else
                    printf("%d", start);
            }
        }
        token = strtok(NULL, STRTOK_KEY);
    }

    free(temp);

    if (arg_c == -1)
        printf("nessun percorso\n");
}

#pragma endregion

#pragma region BaseFunctions

ServiceStation* getStation(int distance) 
{
    int index = getStationIndex(distance);

    if (index == -1)
        return NULL;
    else
        return &stations[index];
}

Auto* getAuto(ServiceStation* st, int autonomy)
{
    if (st != NULL)
    {
        int index = getAutoIndex(st, autonomy);

        if (index >= 0)
            return &st->vehicles[index];
    }

    return NULL;
}

int addServiceStation(ServiceStation st)
{
    int index = 0;

    for (int i = 0; i < stationsLength && index != -1; ++i)
    {
        if (stations[i].distance == st.distance)
            index = -1;
        else if (stations[i].distance < st.distance)
            index++;
        else
            break;
    }

    if (index >= 0)
    {
        ServiceStation* temp = realloc(stations, (stationsLength + 1) * sizeof(ServiceStation));
        if (temp == NULL)
        {
            index = -1;
            mallocError(-1);
        }
        else
        {
            stations = temp;

            for (int i = stationsLength; i > index; --i)
                stations[i] = stations[i - 1];

            stations[index] = st;
            stationsLength++;
        }
    }

    return index;
}

int removeStations(int distance)
{
    int s_index = getStationIndex(distance);
    if (s_index >= 0)
    {
        for (int i = s_index; i < stationsLength - 1; ++i)
            stations[i] = stations[i + 1];

        ServiceStation* temp = realloc(stations, (stationsLength - 1) * sizeof(ServiceStation));
        if (temp == NULL && stationsLength - 1 > 0)
            mallocError(1);

        stations = temp;
        stationsLength--;
    }

    return s_index;
}

int addAuto(ServiceStation* st, Auto a)
{
    int index = 0;

    for (int i = 0; i < st->num_vehicles && index != -1; ++i)
    {
        if (st->vehicles[i].autonomy > a.autonomy)
            index++;
        else
            break;
    }

    if (index >= 0 && st->num_vehicles + 1 <= MAX_VEHICLES)
    {
        Auto* temp = realloc(st->vehicles, (st->num_vehicles + 1) * sizeof(Auto));
        if (temp == NULL)
        {
            index = -1;
            mallocError(-1);
        }
        else
        {
            st->vehicles = temp;

            for (int i = st->num_vehicles; i > index; --i)
                st->vehicles[i] = st->vehicles[i - 1];

            st->vehicles[index] = a;
            st->num_vehicles++;
        }
    }
    else
    {
        printf("Impossibile aggiungere nuovi veicoli.\n");
        index = -1;
    }

    return index;
}

int rmAuto(ServiceStation* st, int autonomy)
{
    int a_index = getAutoIndex(st, autonomy);

    if (a_index >= 0)
    {
        for (int i = a_index; i < st->num_vehicles - 1; ++i)
            st->vehicles[i] = st->vehicles[i + 1];
        
        Auto* temp = realloc(st->vehicles, (st->num_vehicles - 1) * sizeof(Auto));
        if (temp == NULL && st->num_vehicles - 1 > 0)
            mallocError(1);

        st->vehicles = temp;
        st->num_vehicles--;
    }

    return a_index;
}

#pragma endregion

#pragma region Utility

int getStationIndex(int distance)
{
    int f_index = -1;
    for (int i = 0; i < stationsLength && f_index == -1; ++i)
    {
        if (stations[i].distance == distance) 
            f_index = i;
    }

    return f_index;
}

int getAutoIndex(ServiceStation* st, int autonomy)
{
    int f_index = -1;
    for (int i = 0; i < st->num_vehicles && f_index == -1; ++i)
    {
        if (st->vehicles[i].autonomy == autonomy)
            f_index = i;
    }

    return f_index;
}

#pragma endregion

int calculateTrip(int start, int end)
{
    int s_index = getStationIndex(start);
    int e_index = getStationIndex(end);
    int f = -1;

    if (s_index >= 0 && e_index >= 0)
    {
        int* percorso = malloc(stationsLength * sizeof(int));
        int* min_tappe = malloc(stationsLength * sizeof(int));
        int* prev = malloc(stationsLength * sizeof(int));

        if (percorso == NULL || min_tappe == NULL || prev == NULL)
            mallocError(1);
        else
        {
            //solo a livello di byte
            memset(prev, -1, stationsLength * sizeof(int));

            for (int i = 0; i < stationsLength; ++i)
                min_tappe[i] = INT_MAX;
            min_tappe[s_index] = 0;

            int direction = start < end ? 1 : -1;
            int i_limit = direction == 1 ? stationsLength : -1;
            int j_direction = direction;

            for (int i = s_index; i != i_limit; i += direction)
            {
                if (stations[i].num_vehicles > 0)
                {
                    int autonomy = getMaxAutonomy(i);

                    for (int j = i + j_direction; j != i_limit; j += direction)
                    {
                        int diff = stations[j].distance - stations[i].distance;

                        if (diff * direction > 0
                            && abs(diff) <= autonomy)
                        {
                            int potential_min_tappe = min_tappe[i] + 1;
                            if (min_tappe[j] > potential_min_tappe ||
                                (min_tappe[j] == potential_min_tappe && prev[j] > i))
                            {
                                min_tappe[j] = potential_min_tappe;
                                prev[j] = i;
                            }
                        }
                    }
                }
            }

            if (min_tappe[e_index] != INT_MAX)
            {
                int contatore = 0;
                int pos = e_index;

                while (pos != -1) 
                {
                    percorso[contatore++] = stations[pos].distance;
                    pos = prev[pos];
                }

                if (percorso[contatore - 1] == start) 
                {
                    for (int i = contatore - 1; i > 0; i--)
                        printf("%d ", percorso[i]);
                    printf("%d\n", percorso[0]);

                    f = 0;
                }
            }
        }

        if (min_tappe != NULL)
            free(min_tappe);
        if (prev != NULL)
            free(prev);
        if (percorso != NULL)
            free(percorso);
    }

    return f;
}

int getMaxAutonomy(int index)
{
    return stations[index].vehicles[0].autonomy;
}
