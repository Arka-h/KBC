
// C program for writing
// struct to file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *filepointer;
// a struct to read and write
typedef struct question
{
    char string[450];//max_words = 30 each of size_max = 20 total of max 600 char as a string.
}Question;
//Question data type
typedef struct option
{
    char string[200];//4 options each of max_words = 10,each of size_max = 15
}Option;
//Option data type.
typedef struct basic_structure0
{
    short int correct_ans[30] ;//30 correct answers.
    Question questions[30];//30 questions.
    Option options[30][4];//4 options for each question.

}Q_paper0;

typedef struct basic_structure
{   short int correct_ans[45] ;
    Question questions[45] ;
    Option options[45][4] ;
}Q_paper1;


Q_paper0 easy;
Q_paper0 RANdom;
void QUESTIONS(void)
{
    strcpy(easy.questions[0].string ,"The symbol of which arithmetic operation also resembles a letter of the English Alphabet?");
    strcpy(easy.options[0][0].string,"Multiplication");
    strcpy(easy.options[0][1].string,"Subtraction");
    strcpy(easy.options[0][2].string,"Addition");
    strcpy(easy.options[0][3].string,"Division");
    easy.correct_ans[0]=0;

    strcpy(easy.questions[1].string , "Which of the following is called 'falak' in Arabic?");
    strcpy(easy.options[1][0].string,"Moon");
    strcpy(easy.options[1][1].string,"Sky");
    strcpy(easy.options[1][2].string,"Earth");
    strcpy(easy.options[1][3].string,"Air");
    easy.correct_ans[1]=1;

    strcpy(easy.questions[2].string , "Which Mughal emperor was the grandson of Jahangir?");
    strcpy(easy.options[2][0].string,"Shah Alam");
    strcpy(easy.options[2][1].string,"Aurangzeb");
    strcpy(easy.options[2][2].string,"Shah Jahan");
    strcpy(easy.options[2][3].string,"Bahadur Shah");
    easy.correct_ans[2]=1;

    strcpy(easy.questions[3].string , "Where was the Asian Games 2018 held?");
    strcpy(easy.options[3][0].string,"Jakarta and Palembang, Indonesia");
    strcpy(easy.options[3][1].string,"Hangzhou, China");
    strcpy(easy.options[3][2].string,"Pyeongchang, South Korea");
    strcpy(easy.options[3][3].string,"Tokyo, Japan");
    easy.correct_ans[3]=0;

    strcpy(easy.questions[4].string , "Oesophagus, liver, pancreas and intestines are part of which system of a human body?");
    strcpy(easy.options[4][0].string,"Reproductive");
    strcpy(easy.options[4][1].string,"Digestive");
    strcpy(easy.options[4][2].string,"Respiratory");
    strcpy(easy.options[4][3].string,"Nervous");
    easy.correct_ans[4]=1;

    strcpy(easy.questions[5].string , "Which name was India's first prime minister also known?");
    strcpy(easy.options[5][0].string,"Rajaji");
    strcpy(easy.options[5][1].string,"Mahatmaji");
    strcpy(easy.options[5][2].string,"Panditji");
    strcpy(easy.options[5][3].string,"Sardarji");
    easy.correct_ans[5]=2;

    strcpy(easy.questions[6].string , "Who is the first Indian player  to win two singles gold medals in Commonwealth Games?");
    strcpy(easy.options[6][0].string,"Pullela Gopichand");
    strcpy(easy.options[6][1].string,"Saina Nehwal");
    strcpy(easy.options[6][2].string,"Syed Modi");
    strcpy(easy.options[6][3].string,"P V Sindhu");
    easy.correct_ans[6]=1;

    strcpy(easy.questions[7].string , "Which of these phrases means to be affected by an  evil eye?");
    strcpy(easy.options[7][0].string,"Nazar Pherna");
    strcpy(easy.options[7][1].string,"Nazar Lagna");
    strcpy(easy.options[7][2].string,"Nezarana Dena");
    strcpy(easy.options[7][3].string,"Nazar Milana");
    easy.correct_ans[7]=1;

    strcpy(easy.questions[8].string , "Which one of the following constitutes the major population of Kerala?");
    strcpy(easy.options[8][0].string,"Tamilians");
    strcpy(easy.options[8][1].string,"Telegus");
    strcpy(easy.options[8][2].string,"Kannadigas");
    strcpy(easy.options[8][3].string,"Malayalis");
    easy.correct_ans[8]=3;

    strcpy(easy.questions[9].string , "Which of these leaders would not have seen the Taj Mahal in their lifetime?");
    strcpy(easy.options[9][0].string,"Sher Shah Suri");
    strcpy(easy.options[9][1].string,"Aurangzeb");
    strcpy(easy.options[9][2].string,"Shah Alam II");
    strcpy(easy.options[9][3].string,"Bahadur Shah");
    easy.correct_ans[9]=0;

    strcpy(easy.questions[10].string , "In the Hindu Shastra which of these is mentioned as a powerful weapon?");
    strcpy(easy.options[10][0].string,"Dharmastra");
    strcpy(easy.options[10][1].string,"Krishnastra");
    strcpy(easy.options[10][2].string,"Rudrashtra");
    strcpy(easy.options[10][3].string,"bramhastra ");
    easy.correct_ans[10]=3;

    strcpy(easy.questions[11].string , "Which of these actresses is Uday Chopra's bhabi?");
    strcpy(easy.options[11][0].string,"Kajol");
    strcpy(easy.options[11][1].string,"Vidya Balan");
    strcpy(easy.options[11][2].string,"Rani Mukherjee");
    strcpy(easy.options[11][3].string,"Raveena Tandon");
    easy.correct_ans[11]=2;

    strcpy(easy.questions[12].string , "With reference to vehicles, which of these is advised to be used at night?");
    strcpy(easy.options[12][0].string,"Horn");
    strcpy(easy.options[12][1].string,"Hand brake");
    strcpy(easy.options[12][2].string,"Power window");
    strcpy(easy.options[12][3].string,"Dipper");
    easy.correct_ans[12]=3;

    strcpy(easy.questions[13].string , "To which character is the dialogue 'Salim ka pyar tumhe marne nahi degi aur hum tumhe jeene nahi denge' addressed?");
    strcpy(easy.options[13][0].string,"Champakali");
    strcpy(easy.options[13][1].string,"Jalebi bai");
    strcpy(easy.options[13][2].string,"Anarkali");
    strcpy(easy.options[13][3].string,"Chameli");
    easy.correct_ans[13]=2;

    strcpy(easy.questions[14].string , "With respect to investment, what does ppp stand for?");
    strcpy(easy.options[14][0].string,"public project panel");
    strcpy(easy.options[14][1].string,"paid public project");
    strcpy(easy.options[14][2].string,"public project promotion");
    strcpy(easy.options[14][3].string,"public private partnership");
    easy.correct_ans[14]=3;

    strcpy(easy.questions[15].string , "Of what is a Kilobyte a unit?");
    strcpy(easy.options[15][0].string,"Speed of bullet trains");
    strcpy(easy.options[15][1].string,"Speed of light");
    strcpy(easy.options[15][2].string,"Computer memory or data");
    strcpy(easy.options[15][3].string,"Intensity of earthquakes");
    easy.correct_ans[15]=2;

    strcpy(easy.questions[16].string , "When an umpire makes a T signal with his hand during a T20 match, what is he signalling?");
    strcpy(easy.options[16][0].string,"Hit wicket");
    strcpy(easy.options[16][1].string,"Time out");
    strcpy(easy.options[16][2].string,"No ball");
    strcpy(easy.options[16][3].string,"Free hit");
    easy.correct_ans[16]=1;

    strcpy(easy.questions[17].string , "Which of these authors is a mechanical engineer by education?");
    strcpy(easy.options[17][0].string,"Devdutt Pattanak");
    strcpy(easy.options[17][1].string,"Chetan Bhagat");
    strcpy(easy.options[17][2].string,"Aswin Sanghi");
    strcpy(easy.options[17][3].string,"Amish Tripathi");
    easy.correct_ans[17]=1;

    strcpy(easy.questions[18].string , "The ruler of which of these kingdoms was called Rana or Maharana?");
    strcpy(easy.options[18][0].string,"Junagarh");
    strcpy(easy.options[18][1].string,"Jaipur");
    strcpy(easy.options[18][2].string,"Kashmir");
    strcpy(easy.options[18][3].string,"Mewar ");
    easy.correct_ans[18]=3;

    strcpy(easy.questions[19].string , "Who is the head of the National Disaster Management Authority of India?");
    strcpy(easy.options[19][0].string,"Union Environment Minister");
    strcpy(easy.options[19][1].string,"Union Home Minister");
    strcpy(easy.options[19][2].string,"President");
    strcpy(easy.options[19][3].string,"Prime Minister");
    easy.correct_ans[19]=3;

    strcpy(easy.questions[20].string , "Which of these is not a crispy snack?");
    strcpy(easy.options[20][0].string,"Khakhra");
    strcpy(easy.options[20][1].string,"Papri");
    strcpy(easy.options[20][2].string,"Papad");
    strcpy(easy.options[20][3].string,"Dhokhla ");
    easy.correct_ans[20]=3;

    strcpy(easy.questions[21].string , "In which of these sports does a player not require any equipment?");
    strcpy(easy.options[21][0].string,"Snooker");
    strcpy(easy.options[21][1].string,"Kabaddi");
    strcpy(easy.options[21][2].string,"Gili-danda");
    strcpy(easy.options[21][3].string,"Polo");
    easy.correct_ans[21]=1;

    strcpy(easy.questions[22].string , "Ruquaia Begum was the wife of which Mughal Emperor?");
    strcpy(easy.options[22][0].string,"Aurangzeb");
    strcpy(easy.options[22][1].string,"Akbar");
    strcpy(easy.options[22][2].string,"Jahangir");
    strcpy(easy.options[22][3].string,"Humayun");
    easy.correct_ans[22]=1;

    strcpy(easy.questions[23].string , "Which of these is a core ingredient of the south Indian dish Rasam?");
    strcpy(easy.options[23][0].string,"Cucumber");
    strcpy(easy.options[23][1].string,"Rajma");
    strcpy(easy.options[23][2].string,"Brinjal");
    strcpy(easy.options[23][3].string,"Tamarind");
    easy.correct_ans[23]=3;

    strcpy(easy.questions[24].string , "Which is the tallest bird in the world, standing at about 6 feet tall?");
    strcpy(easy.options[24][0].string,"Ostrich");
    strcpy(easy.options[24][1].string,"Trumpeter Swan");
    strcpy(easy.options[24][2].string,"Sarus crane");
    strcpy(easy.options[24][3].string,"Toco Toucan");
    easy.correct_ans[24]=0;

    strcpy(easy.questions[25].string , "In the tale Punarmushiko Bhava which animal is turned into a cat, dog and lion by a sage?");
    strcpy(easy.options[25][0].string,"Squirrel");
    strcpy(easy.options[25][1].string,"Mouse");
    strcpy(easy.options[25][2].string,"Elephant");
    strcpy(easy.options[25][3].string,"Frog");
    easy.correct_ans[25]=1;

    strcpy(easy.questions[26].string , "By which name is the Sonepur Mela, the famous cattle fair of Bihar also known as?");
    strcpy(easy.options[26][0].string,"Pushkar fair");
    strcpy(easy.options[26][1].string,"Saurath Sabha");
    strcpy(easy.options[26][2].string,"Pitrapaksha mela");
    strcpy(easy.options[26][3].string,"Harihar kshatra mela");
    easy.correct_ans[26]=3;

    strcpy(easy.questions[27].string , "Which ruler, was the charioteer at Devaki's wedding with Vasudeva(Krishna's parents)?");
    strcpy(easy.options[27][0].string,"Jayadratha");
    strcpy(easy.options[27][1].string,"Kansa");
    strcpy(easy.options[27][2].string,"Shishupala");
    strcpy(easy.options[27][3].string,"Jarashandha");
    easy.correct_ans[27]=1;

    strcpy(easy.questions[28].string , "What is the shape of a boxing ring?");
    strcpy(easy.options[28][0].string,"Square");
    strcpy(easy.options[28][1].string,"Octagon");
    strcpy(easy.options[28][2].string,"Hexagon");
    strcpy(easy.options[28][3].string,"Circle");
    easy.correct_ans[28]=0;

    strcpy(easy.questions[29].string , "Where will Olympics 2020 be held?");
    strcpy(easy.options[29][0].string,"Jakarta and Palembang, Indonesia");
    strcpy(easy.options[29][1].string,"Hangzhou, China");
    strcpy(easy.options[29][2].string,"Pyeongchang, South Korea");
    strcpy(easy.options[29][3].string,"Tokyo, Japan");
    easy.correct_ans[29]=3;
}
void CHECK()
{
    if (filepointer == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
}
void PRINT()
{
    for(int i=0;i<30;i++)
    { printf("\n%d)%s\n",i+1,RANdom.questions[i].string);

        for(int j=0;j<4;j++)
    	{
    		printf("\n%c| %s\n",65+j,RANdom.options[i][j].string);
    	}
        printf("correct answer:%c",65+RANdom.correct_ans[i]);
    }
}
int main ()
{
    // open file for writing
    filepointer = fopen("KBC_QBE.bin", "w");
    CHECK();
    //The array defined inside struct is a constant type, and can't be initialised,
    //hence only operations can be used to change its content

    QUESTIONS();

    fwrite (&easy, sizeof(Q_paper0), 1, filepointer);
    CHECK();
    fclose (filepointer);
    // FILE CLOSED
    filepointer=fopen("KBC_QBE.bin","r");

    CHECK();
    (void)fread(&RANdom, sizeof(Q_paper0), 1, filepointer);
    PRINT();

    fclose(filepointer);
    return 0;
}

