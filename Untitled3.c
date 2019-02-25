
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

Q_paper0 hard;
Q_paper0 RANdom;
void QUESTIONS()
{
    strcpy(hard.questions[0].string , "Which of the following rivers does not flow into the Arabian Sea?");
    strcpy(hard.options[0][0].string,"Tungabhadra");
    strcpy(hard.options[0][1].string,"Sabarmati");
    strcpy(hard.options[0][2].string,"Mandovi");
    strcpy(hard.options[0][3].string,"Narmada");
    hard.correct_ans[0]=1;

    strcpy(hard.questions[1].string , "Which of these is not a traditional dish in the multi-course meal Wazwaan?");
    strcpy(hard.options[1][0].string,"Roghan Josh");
    strcpy(hard.options[1][1].string,"Gushtaba");
    strcpy(hard.options[1][2].string,"Murgh Musallam");
    strcpy(hard.options[1][3].string,"Tabak Maaz");
    hard.correct_ans[1]=1;

    strcpy(hard.questions[2].string , "Against which team did Parvez Rasool make his ODI debut for India in June 2014?");
    strcpy(hard.options[2][0].string,"Pakistan");
    strcpy(hard.options[2][1].string,"Sri Lanka");
    strcpy(hard.options[2][2].string,"Bangladesh");
    strcpy(hard.options[2][3].string,"Zimbabwe");
    hard.correct_ans[2]=2;

    strcpy(hard.questions[3].string , "Which national park was named so because the local Maharaja relocated ten villages from the area and declared it a hunting preserve?");
    strcpy(hard.options[3][0].string,"Ranthambore");
    strcpy(hard.options[3][1].string,"Hazaribagh");
    strcpy(hard.options[3][2].string,"Kaziranga");
    strcpy(hard.options[3][3].string,"Dachigam ");
    hard.correct_ans[3]=3;

    strcpy(hard.questions[4].string , "Kalgoorlie and Coolgardie - places famous for gold mines are located in:");
    strcpy(hard.options[4][0].string,"Australia");
    strcpy(hard.options[4][1].string,"U S A");
    strcpy(hard.options[4][2].string,"England");
    strcpy(hard.options[4][3].string,"South Africa");
    hard.correct_ans[4]=0;

    strcpy(hard.questions[5].string , "Which composer was also credited with other names like Annasaheb, Ram Chitalkar and Shyamoo?");
    strcpy(hard.options[5][0].string,"Salil Chowdhury");
    strcpy(hard.options[5][1].string,"Khemchand Prakash");
    strcpy(hard.options[5][2].string,"C Ramachandra");
    strcpy(hard.options[5][3].string,"S D Burman");
    hard.correct_ans[5]=2;

    strcpy(hard.questions[6].string , "Which candidate of the LS elections got her name from an act under which her father was jailed during the emergency?");
    strcpy(hard.options[6][0].string,"Priya Dutt");
    strcpy(hard.options[6][1].string,"Misa Bharti");
    strcpy(hard.options[6][2].string,"Smriti Irani");
    strcpy(hard.options[6][3].string,"Dimple Yadav");
    hard.correct_ans[6]=1;

    strcpy(hard.questions[7].string , "Who was the first Indian woman to win a pilot's license?  ");
    strcpy(hard.options[7][0].string,"Urmila K Parikh");
    strcpy(hard.options[7][1].string,"Prem Mathur");
    strcpy(hard.options[7][2].string,"Durba Banerjee");
    strcpy(hard.options[7][3].string,"Saudamini Deshmukh");
    hard.correct_ans[7]=0;

    strcpy(hard.questions[8].string , "How many different countries did PM Modi visit after he became prime minister?  ");
    strcpy(hard.options[8][0].string,"49");
    strcpy(hard.options[8][1].string,"50");
    strcpy(hard.options[8][2].string,"59");
    strcpy(hard.options[8][3].string,"69");
    hard.correct_ans[8]=2;

    strcpy(hard.questions[9].string , "On the birth centenary of which ghazal singer did the ministry of culture, government of India issue commemorative coins in 2014?");
    strcpy(hard.options[9][0].string,"Begum Akhtar");
    strcpy(hard.options[9][1].string,"Shamshad Begum");
    strcpy(hard.options[9][2].string,"Mehdi Hasan");
    strcpy(hard.options[9][3].string,"Noor Jehan");
    hard.correct_ans[9]=0;

    strcpy(hard.questions[10].string , "Which of these palaces was built by Maharaja Sayajirao Gaekwad III in the 19th century?  ");
    strcpy(hard.options[10][0].string,"City Palace, Jaipur");
    strcpy(hard.options[10][1].string,"Vijay Vilas Palace, Bhavnagar");
    strcpy(hard.options[10][2].string,"Umaid Bhawan palace, Jodhpur");
    strcpy(hard.options[10][3].string,"Laksmi Vilas Palace, Vadodara");
    hard.correct_ans[10]=3;

    strcpy(hard.questions[11].string , "With the break up of the Soviet Union in 1991 Crimea became part of which county?");
    strcpy(hard.options[11][0].string,"Russia");
    strcpy(hard.options[11][1].string,"Belarus");
    strcpy(hard.options[11][2].string,"Armenia");
    strcpy(hard.options[11][3].string,"Ukraine");
    hard.correct_ans[11]=3;

    strcpy(hard.questions[12].string , "Who administered the oath to office to the first president Dr.Rajendra Prasad on 26th January 1950?");
    strcpy(hard.options[12][0].string,"Lord Mountbatten");
    strcpy(hard.options[12][1].string,"Hiralal Kania");
    strcpy(hard.options[12][2].string,"Sukumar Sen");
    strcpy(hard.options[12][3].string,"C Rajagopalacharya");
    hard.correct_ans[12]=1;


    strcpy(hard.questions[13].string , "Who founded the organization Bachpan Bachao Andolan in 1980? ");
    strcpy(hard.options[13][0].string,"Dr. Prakash Amte");
    strcpy(hard.options[13][1].string,"Rippan Kapur");
    strcpy(hard.options[13][2].string,"Kailash Satyarthi");
    strcpy(hard.options[13][3].string,"Shantha Sinha");
    hard.correct_ans[13]=2;

    strcpy(hard.questions[14].string , "Which of these people has served as both chief minister and governor?  ");
    strcpy(hard.options[14][0].string,"Kamla Beniwal");
    strcpy(hard.options[14][1].string,"Uma Bharti");
    strcpy(hard.options[14][2].string,"Sheila Dixit");
    strcpy(hard.options[14][3].string,"Margaret Alva ");
    hard.correct_ans[14]=2;

    strcpy(hard.questions[15].string , "Which Param Veer Chakra recipient was thought to be dead in 1962 but returned alive from a prisoner of war camp?");
    strcpy(hard.options[15][0].string,"Naik Jadunath Singh");
    strcpy(hard.options[15][1].string,"Major Dhan Singh Thapa");
    strcpy(hard.options[15][2].string,"Lance Naik Karam Singh");
    strcpy(hard.options[15][3].string,"Captain Gurbachan Singh Salaria");
    hard.correct_ans[15]=1;

    strcpy(hard.questions[16].string , "Which endangered animal of the Kutch region in India has a wildlife sanctuary named after it?");
    strcpy(hard.options[16][0].string,"Wild boar");
    strcpy(hard.options[16][1].string,"Wild ass");
    strcpy(hard.options[16][2].string,"Nilgai");
    strcpy(hard.options[16][3].string,"Asiatic lion");
    hard.correct_ans[16]=1;

    strcpy(hard.questions[17].string , "Which of these players made his ODI and test debut for India in the same year?");
    strcpy(hard.options[17][0].string,"Rohit Sharma");
    strcpy(hard.options[17][1].string,"Ajinkya Rahane");
    strcpy(hard.options[17][2].string,"Stuart Binny");
    strcpy(hard.options[17][3].string,"Ravindra Jadeja");
    hard.correct_ans[17]=2;

    strcpy(hard.questions[18].string , "Which one of the following is found under the Indian Constitution?");
    strcpy(hard.options[18][0].string,"Preponderance of Executive");
    strcpy(hard.options[18][1].string,"Popular Sovereignty");
    strcpy(hard.options[18][2].string,"Judicial Supremacy");
    strcpy(hard.options[18][3].string,"Parliamentary Sovereignty");
    hard.correct_ans[18]=1;

    strcpy(hard.questions[19].string , "The doctrine of Pleasure tenure of the 'Civil Servants' has been Incorporated from the Constitution of:");
    strcpy(hard.options[19][0].string,"China");
    strcpy(hard.options[19][1].string,"U S A");
    strcpy(hard.options[19][2].string,"U K");
    strcpy(hard.options[19][3].string,"France");
    hard.correct_ans[19]=2;

    strcpy(hard.questions[20].string , "In Which of the Following Cases , the Supreme Court ruled that the Preamble is not a part of the Constitution?");
    strcpy(hard.options[20][0].string,"S.R. Bommai Case");
    strcpy(hard.options[20][1].string,"Kesavananda Bharti Case");
    strcpy(hard.options[20][2].string,"Re Berubari Union Case");
    strcpy(hard.options[20][3].string,"Golaknath Case");
    hard.correct_ans[20]=2;

    strcpy(hard.questions[21].string , "Which state was set to host World's largest Water Colour Festival from August 23 to August 27,2018?");
    strcpy(hard.options[21][0].string,"Maharashtra");
    strcpy(hard.options[21][1].string,"Jharkhand");
    strcpy(hard.options[21][2].string,"Uttar Pradesh");
    strcpy(hard.options[21][3].string,"Himachal Pradesh");
    hard.correct_ans[21]=1;

    strcpy(hard.questions[22].string , "Country's first inter state transmission system (ISTS) auction is commissioned in which city?");
    strcpy(hard.options[22][0].string,"Lucknow");
    strcpy(hard.options[22][1].string,"Pune");
    strcpy(hard.options[22][2].string,"Bhuj");
    strcpy(hard.options[22][3].string,"Gorakhpur");
    hard.correct_ans[22]=2;

    strcpy(hard.questions[23].string , "Which bowler has set a new world record of being the most economical bowler in the T20 cricket?");
    strcpy(hard.options[23][0].string,"Irfan Khan");
    strcpy(hard.options[23][1].string,"Mohd. Ariz");
    strcpy(hard.options[23][2].string,"Mohd. Irfan");
    strcpy(hard.options[23][3].string,"Shadab Khan");
    hard.correct_ans[23]=2;

    strcpy(hard.questions[24].string , "Who bagged a bronze medal in Men's 10,000 m Athletics event at the Asian Games 2018?");
    strcpy(hard.options[24][0].string,"Lakshmanan Govindan");
    strcpy(hard.options[24][1].string,"Abhinav Bindra");
    strcpy(hard.options[24][2].string,"Jinson Johnson");
    strcpy(hard.options[24][3].string,"Dutee Chand");
    hard.correct_ans[24]=0;

    strcpy(hard.questions[25].string , "When was SBI founded?");
    strcpy(hard.options[25][0].string,"1970");
    strcpy(hard.options[25][1].string,"1955");
    strcpy(hard.options[25][2].string,"1965");
    strcpy(hard.options[25][3].string,"1960");
    hard.correct_ans[25]=1;

    strcpy(hard.questions[26].string , "Who was appointed as new Secretary General of ASSOCHAM(Associated Chambers of Commerce and Industry of India)?");
    strcpy(hard.options[26][0].string,"Usha AnanthSubramaniyan");
    strcpy(hard.options[26][1].string,"Lakshman Sen");
    strcpy(hard.options[26][2].string,"Uday Kotak");
    strcpy(hard.options[26][3].string,"Uday Kumar Verma");
    hard.correct_ans[26]=3;

    strcpy(hard.questions[27].string , "When was ASSOCHAM founded?");
    strcpy(hard.options[27][0].string,"1930");
    strcpy(hard.options[27][1].string,"1945");
    strcpy(hard.options[27][2].string,"1919");
    strcpy(hard.options[27][3].string,"1920");
    hard.correct_ans[27]=3;

    strcpy(hard.questions[28].string , "Who has been elected as the new Chairman of Indian Banks Association?");
    strcpy(hard.options[28][0].string,"PS Jayaram");
    strcpy(hard.options[28][1].string,"Mahesh Kumar Jain");
    strcpy(hard.options[28][2].string,"Rajnish Kumar");
    strcpy(hard.options[28][3].string,"Sunil Mehta");
    hard.correct_ans[28]=3;

    strcpy(hard.questions[29].string , "Tadoba National Park known for sheltering tiger, panther and bear is located in:");
    strcpy(hard.options[29][0].string,"Assam");
    strcpy(hard.options[29][1].string,"Maharashtra");
    strcpy(hard.options[29][2].string,"Karnataka");
    strcpy(hard.options[29][3].string,"Tamil Nadu");
    hard.correct_ans[29]=1;
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
        printf("correct answer:%c\n",65+RANdom.correct_ans[i]);
    }
}

int main ()
{


    // open file for writing
    filepointer = fopen("KBC_QBH.bin", "w");

    //The array defined inside struct is a constant type, and can't be initialised,
    //hence only operations can be used to change its content

    QUESTIONS();

    fwrite (&hard, sizeof(Q_paper0), 1, filepointer);
    CHECK();
    // close file
    fclose (filepointer);

    filepointer = fopen("KBC_QBH.bin", "r");
    (void)fread(&RANdom,sizeof(Q_paper0),1,filepointer);
    PRINT();
    return 0;
}

