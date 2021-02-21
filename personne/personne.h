typedef struct personne personne;
struct personne{
    char username[100];
    float money;
    int gender;
    int role;
    int dragon;
};

int create_player(int nbplayer);
int end();