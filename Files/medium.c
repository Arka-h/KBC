
// C program for writing
// struct to file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// a struct to read and write
FILE *filepointer;
typedef struct question
{
    char string[250];//max_words = 30 each of size_max = 20 total of max 600 char as a string.
}Question;
//Question data type
typedef struct option
{
    char string[100];//4 options each of max_words = 10,each of size_max = 15
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

Q_paper1 medium;
Q_paper1 RANdom;
void QUESTIONS()
{
    strcpy(medium.questions[0].string, "Which of these Indian athletes refused to accept the bronze medal awarded to her after a controversial bout in the Asian Games?");
    strcpy(medium.options[0][0].string,"Shiva Thapa");
    strcpy(medium.options[0][1].string,"L Sarita Devi");
    strcpy(medium.options[0][2].string,"Annu Rani");
    strcpy(medium.options[0][3].string,"Devendro Singh Laishram");
    medium.correct_ans[0]=1;

    strcpy(medium.questions[1].string , "Which song did Kavi Pradeep compose to pay homage to the martyrs of the Indo-China war?");
    strcpy(medium.options[1][0].string,"Aye Mere Watan ke Logon");
    strcpy(medium.options[1][1].string,"Mere Desh ki Dharti");
    strcpy(medium.options[1][2].string,"Apni Azadi Ko Hum");
    strcpy(medium.options[1][3].string,"Ab Tumhare Hawale Watan");
    medium.correct_ans[1]=0;

	strcpy(medium.questions[2].string , "In which American city is the famous indoor stadium Madison Square Garden located?");
    strcpy(medium.options[2][0].string,"Washington, DC");
    strcpy(medium.options[2][1].string,"New York City");
    strcpy(medium.options[2][2].string,"San Francisco");
    strcpy(medium.options[2][3].string,"Los Angeles");
    medium.correct_ans[2]=1;

	strcpy(medium.questions[3].string , "The name of which of these cities means a fort?");
    strcpy(medium.options[3][0].string,"Dantewada");
    strcpy(medium.options[3][1].string,"Ambikapur");
    strcpy(medium.options[3][2].string,"Durg");
    strcpy(medium.options[3][3].string,"Jagdalpur");
    medium.correct_ans[3]=2;

	strcpy(medium.questions[4].string , "After the battle of Kurukshetra who gave Yudhisthira lessons on Raj Dharma?");
    strcpy(medium.options[4][0].string,"Krishna");
    strcpy(medium.options[4][1].string,"Bhishma");
    strcpy(medium.options[4][2].string,"Vidur");
    strcpy(medium.options[4][3].string,"Ved Vyas");
    medium.correct_ans[4]=1;

	strcpy(medium.questions[5].string , "Kathiawari,Marwari,Zanskari and Bhutia are all breeds of what animal found in India?");
    strcpy(medium.options[5][0].string,"Camel");
    strcpy(medium.options[5][1].string,"Bull");
    strcpy(medium.options[5][2].string,"Cow");
    strcpy(medium.options[5][3].string,"Horse");
    medium.correct_ans[5]=3;

	strcpy(medium.questions[6].string , "The spice saffron is obtained from which flower?");
    strcpy(medium.options[6][0].string,"Rhododendron");
    strcpy(medium.options[6][1].string,"Crocus");
    strcpy(medium.options[6][2].string,"Tulip");
    strcpy(medium.options[6][3].string,"Lady's Slipper");
    medium.correct_ans[6]=1;

	strcpy(medium.questions[7].string , "Which of these rulers were contemporaries of each other?");
    strcpy(medium.options[7][0].string,"Humayun and Shivaji");
    strcpy(medium.options[7][1].string,"Harshavardhana and Prithviraj Chauhan");
    strcpy(medium.options[7][2].string,"Ashoka and Samudragupta");
    strcpy(medium.options[7][3].string,"Maharana Pratap and Akbar");
    medium.correct_ans[7]=3;

	strcpy(medium.questions[8].string , "According to the Ramayana which was the only ornament of Sita that Laksmana recognized, among the ones found by Sugriva?");
    strcpy(medium.options[8][0].string,"Chudamani");
    strcpy(medium.options[8][1].string,"Bracelet");
    strcpy(medium.options[8][2].string,"Anklet");
    strcpy(medium.options[8][3].string,"Earring");
    medium.correct_ans[8]=2;

	strcpy(medium.questions[9].string , "The name of which of these leaders includes a title he got upon graduation?");
    strcpy(medium.options[9][0].string,"P V Narshimha Rao");
    strcpy(medium.options[9][1].string,"Giani Zail Singh");
    strcpy(medium.options[9][2].string,"Lal Bahadur Shastri");
    strcpy(medium.options[9][3].string,"Atal Bihari Vajpayee");
    medium.correct_ans[9]=2;

	strcpy(medium.questions[10].string , "Which of these is celebrated during sawaan purnima?");
    strcpy(medium.options[10][0].string,"Suraksha chakra");
    strcpy(medium.options[10][1].string,"Prem dhaaga");
    strcpy(medium.options[10][2].string,"Sneh sutra");
    strcpy(medium.options[10][3].string,"Raksha bandhan");
    medium.correct_ans[10]=3;

	strcpy(medium.questions[11].string , "In which sport has Jitu Rai won individual gold medals in international games?");
    strcpy(medium.options[11][0].string,"Shooting");
    strcpy(medium.options[11][1].string,"Weight lifting");
    strcpy(medium.options[11][2].string,"Boxing");
    strcpy(medium.options[11][3].string,"Judo");
    medium.correct_ans[11]=0;

	strcpy(medium.questions[12].string , "What is the name given to the cyclone passing through the coastal areas of Odissa and Andhra Pradesh in 2014?");
    strcpy(medium.options[12][0].string,"Hudhud");
    strcpy(medium.options[12][1].string,"Titli");
    strcpy(medium.options[12][2].string,"Bijli");
    strcpy(medium.options[12][3].string,"Ockhi");
    medium.correct_ans[12]=1;

	strcpy(medium.questions[13].string , "In the 2018 Asian games on which event did India win gold,silver,bronze medals in both male and female categories?");
    strcpy(medium.options[13][0].string,"Archery");
    strcpy(medium.options[13][1].string,"Kabaddi");
    strcpy(medium.options[13][2].string,"Hockey");
    strcpy(medium.options[13][3].string,"Athletics");
    medium.correct_ans[13]=3;

	strcpy(medium.questions[14].string , "Which of these names is a part of a play by Kalidas?");
    strcpy(medium.options[14][0].string,"Menaka");
    strcpy(medium.options[14][1].string,"Rambha");
    strcpy(medium.options[14][2].string,"Tilottama");
    strcpy(medium.options[14][3].string,"Urvashi");
    medium.correct_ans[14]=3;

	strcpy(medium.questions[15].string , "Test cricketer Madav Matri was the maternal uncle of which other test cricketer?");
    strcpy(medium.options[15][0].string,"Sunil Gavaskar");
    strcpy(medium.options[15][1].string,"Ravi Shastri");
    strcpy(medium.options[15][2].string,"Dilip Vengsarkar");
    strcpy(medium.options[15][3].string,"Anshuman Gaekwad");
    medium.correct_ans[15]=0;

	strcpy(medium.questions[16].string , "The first of which of these diseases in humans was reported in Hong Kong in 1997?");
    strcpy(medium.options[16][0].string,"Chikungunia");
    strcpy(medium.options[16][1].string,"Mad cow disease");
    strcpy(medium.options[16][2].string,"Yellow fever");
    strcpy(medium.options[16][3].string,"Bird flu");
    medium.correct_ans[16]=3;

	strcpy(medium.questions[17].string , "The 2018 Nobel prize for physics was awarded for?");
    strcpy(medium.options[17][0].string,"Topological phase transitions and topological phases of matter");
    strcpy(medium.options[17][1].string,"Blue light emitting diodes");
    strcpy(medium.options[17][2].string,"Graphene");
    strcpy(medium.options[17][3].string,"Optical tweezers and their application to biological systems");
    medium.correct_ans[17]=3;

	strcpy(medium.questions[18].string , "Which of these festivals is celebrated in the month of Maagh?");
    strcpy(medium.options[18][0].string,"Vasant Panchami");
    strcpy(medium.options[18][1].string,"Ganesh Chaturthi");
    strcpy(medium.options[18][2].string,"Buddha Purnima");
    strcpy(medium.options[18][3].string,"Ram Navami");
    medium.correct_ans[18]=0;

	strcpy(medium.questions[19].string , "Which scientists discovered the inert gas neon?");
    strcpy(medium.options[19][0].string,"William Perkin and Frederick Donnan");
    strcpy(medium.options[19][1].string,"Humphrey Davy and Davies Gilbert");
    strcpy(medium.options[19][2].string,"William Ramsay and Morris Travers");
    strcpy(medium.options[19][3].string,"Joseph Priestley and Joseph Black");
    medium.correct_ans[19]=2;

	strcpy(medium.questions[20].string , "Which Danava king was the architect for both the Gods and Asuras?");
    strcpy(medium.options[20][0].string,"Sukracharya");
    strcpy(medium.options[20][1].string,"Maya");
    strcpy(medium.options[20][2].string,"Viswakarma");
    strcpy(medium.options[20][3].string,"Sunda");
    medium.correct_ans[20]=1;

	strcpy(medium.questions[21].string , "The first film to get a national award for Best Feature film was made in which language?");
    strcpy(medium.options[21][0].string,"Bengali");
    strcpy(medium.options[21][1].string,"Hindi");
    strcpy(medium.options[21][2].string,"Marathi");
    strcpy(medium.options[21][3].string,"Malayalam");
    medium.correct_ans[21]=2;

	strcpy(medium.questions[22].string , "The 44th Amendment of the Indian Constitution withdraw the Fundamental Right");
    strcpy(medium.options[22][0].string,"To constitutional remedies");
    strcpy(medium.options[22][1].string,"Against exploitation");
    strcpy(medium.options[22][2].string,"To freedom of religion");
    strcpy(medium.options[22][3].string,"To property");
    medium.correct_ans[22]=3;

	strcpy(medium.questions[23].string , "The Proper authority to specify which caste or Tribe shall be deemed to be scheduled castes or tribes is the:");
    strcpy(medium.options[23][0].string,"President of India");
    strcpy(medium.options[23][1].string,"Committee on the Welfare of SC & ST");
    strcpy(medium.options[23][2].string,"Parliament");
    strcpy(medium.options[23][3].string,"National commission for Scheduled Castes and Scheduled Tribes");
    medium.correct_ans[23]=0;

	strcpy(medium.questions[24].string , "Which railway station is set to be renamed after former PM Atal Bihari Vajpayee?");
    strcpy(medium.options[24][0].string,"Satna railway station");
    strcpy(medium.options[24][1].string,"Panna railway station");
    strcpy(medium.options[24][2].string,"Charbagh railway station");
    strcpy(medium.options[24][3].string,"Habibganj railway station");
    medium.correct_ans[24]=3;

	strcpy(medium.questions[25].string , "Which of these are not Commonwealth Nations?");
    strcpy(medium.options[25][0].string,"Pakistan");
    strcpy(medium.options[25][1].string,"United Kingdom");
    strcpy(medium.options[25][2].string,"Nigeria");
    strcpy(medium.options[25][3].string,"Nepal");
    medium.correct_ans[25]=3;

	strcpy(medium.questions[26].string , "Which of these fermions are not quarks?");
    strcpy(medium.options[26][0].string,"Up");
    strcpy(medium.options[26][1].string,"Charm");
    strcpy(medium.options[26][2].string,"Tau");
    strcpy(medium.options[26][3].string,"Strange");
    medium.correct_ans[26]=2;

	strcpy(medium.questions[27].string , "'India Wage Report' is published by which organization?");
    strcpy(medium.options[27][0].string,"UNO");
    strcpy(medium.options[27][1].string,"ILO");
    strcpy(medium.options[27][2].string,"WHO");
    strcpy(medium.options[27][3].string,"UNESCO");
    medium.correct_ans[27]=1;

	strcpy(medium.questions[28].string , "Which state AIIMS will be renamed after former PM of India, Shri Atal Bihari Vajpayee?");
    strcpy(medium.options[28][0].string,"Tamil Nadu");
    strcpy(medium.options[28][1].string,"Uttar Pradesh");
    strcpy(medium.options[28][2].string,"Andhra Pradesh");
    strcpy(medium.options[28][3].string,"Himachal Pradesh");
    medium.correct_ans[28]=2;

	strcpy(medium.questions[29].string , "Recently ,Gopal Bose passed away.He was related to which field?");
    strcpy(medium.options[29][0].string,"Actor");
    strcpy(medium.options[29][1].string,"Journalist");
    strcpy(medium.options[29][2].string,"Singer");
    strcpy(medium.options[29][3].string,"Sports");
    medium.correct_ans[29]=3;

	strcpy(medium.questions[30].string , "Fouaad Mirza is related to which sports?");
    strcpy(medium.options[30][0].string,"Sprint");
    strcpy(medium.options[30][1].string,"Tennis");
    strcpy(medium.options[30][2].string,"Badminton");
    strcpy(medium.options[30][3].string,"Equestrian");
    medium.correct_ans[30]=3;

	strcpy(medium.questions[31].string , "Where is the HQ of International Labour Organization(ILO)?");
    strcpy(medium.options[31][0].string,"Beijing");
    strcpy(medium.options[31][1].string,"Geneva");
    strcpy(medium.options[31][2].string,"New York");
    strcpy(medium.options[31][3].string,"Tokyo");
    medium.correct_ans[31]=1;

	strcpy(medium.questions[32].string , "The recently signed MoU between Integrated Defence Staff and which organization aims to set up telemedicine nodes for soldiers in\n high-altitude areas?");
    strcpy(medium.options[32][0].string,"DRDO");
    strcpy(medium.options[32][1].string,"VSSC");
    strcpy(medium.options[32][2].string,"BARC");
    strcpy(medium.options[32][3].string,"ISRO");
    medium.correct_ans[32]=3;

	strcpy(medium.questions[33].string , "Mizzima Media Group, which was recently in news, is a company of which country?");
    strcpy(medium.options[33][0].string,"Japan");
    strcpy(medium.options[33][1].string,"Italy");
    strcpy(medium.options[33][2].string,"Sri Lanka");
    strcpy(medium.options[33][3].string,"Myanmar");
    medium.correct_ans[33]=3;

	strcpy(medium.questions[34].string , "India's first-ever test flight powered by biojet fuel was successfully conducted by which airline?");
    strcpy(medium.options[34][0].string,"SpiceJet");
    strcpy(medium.options[34][1].string,"Air India");
    strcpy(medium.options[34][2].string,"JetLite");
    strcpy(medium.options[34][3].string,"Vistara");
    medium.correct_ans[34]=0;

	strcpy(medium.questions[35].string , "Who is the author of the book 'Moving On, Moving Forward: A year in Office'?");
    strcpy(medium.options[35][0].string,"Sumitra Mahajan");
    strcpy(medium.options[35][1].string,"Anand Sharma");
    strcpy(medium.options[35][2].string,"Venkaiah Naidu");
    strcpy(medium.options[35][3].string,"Arun Jaitley");
    medium.correct_ans[35]=2;

	strcpy(medium.questions[36].string , "According to Reserve Bank of India (RBI)'s annual data, which country has topped the India's FDI chart in FY18?");
    strcpy(medium.options[36][0].string,"Netherlands");
    strcpy(medium.options[36][1].string,"France");
    strcpy(medium.options[36][2].string,"Mauritius");
    strcpy(medium.options[36][3].string,"Singapore");
    medium.correct_ans[36]=2;

	strcpy(medium.questions[37].string , "Indian men's hockey team defeated which country to win bronze at the 2018 Asian Games?");
    strcpy(medium.options[37][0].string,"Indonesia");
    strcpy(medium.options[37][1].string,"Japan");
    strcpy(medium.options[37][2].string,"South Korea");
    strcpy(medium.options[37][3].string,"Pakistan");
    medium.correct_ans[37]=3;

	strcpy(medium.questions[38].string , "Arthur Pereira, who passed away recently, was associated which which sports?");
    strcpy(medium.options[38][0].string,"Football");
    strcpy(medium.options[38][1].string,"Hockey");
    strcpy(medium.options[38][2].string,"Chess");
    strcpy(medium.options[38][3].string,"Boxing");
    medium.correct_ans[38]=0;

	strcpy(medium.questions[39].string , "What was the theme of the 2018 World Coconut Day (WCD)?");
    strcpy(medium.options[39][0].string,"Coconut for Good Health, Wealth & Wellness");
    strcpy(medium.options[39][1].string,"Coconut for Family Nutrition, Health, and Wellness");
    strcpy(medium.options[39][2].string,"Coconut for Healthy Life");
    strcpy(medium.options[39][3].string,"Coconut: A Healthy Drink");
    medium.correct_ans[39]=0;

	strcpy(medium.questions[40].string , "Which Indian sportsperson was the India's flag-bearer at the closing ceremony in the 18th Asian Games?");
    strcpy(medium.options[40][0].string,"Rani Rampal");
    strcpy(medium.options[40][1].string,"Rahi Sarnobat");
    strcpy(medium.options[40][2].string,"Bajrang Punia");
    strcpy(medium.options[40][3].string,"Vinesh Phogat");
    medium.correct_ans[40]=0;

	strcpy(medium.questions[41].string , "Which state government has decided to organise employment camps for martyrs' families?");
    strcpy(medium.options[41][0].string,"Punjab");
    strcpy(medium.options[41][1].string,"Madhya Pradesh");
    strcpy(medium.options[41][2].string,"Haryana");
    strcpy(medium.options[41][3].string,"Rajasthan");
    medium.correct_ans[41]=3;

	strcpy(medium.questions[42].string , "Rikako Ikee, who has become the first female athlete to be named the Most Valuable Player (MVP) at Asian Games,\n is from which country?");
    strcpy(medium.options[42][0].string,"Japan");
    strcpy(medium.options[42][1].string,"China");
    strcpy(medium.options[42][2].string,"North Korea");
    strcpy(medium.options[42][3].string,"South Korea");
    medium.correct_ans[42]=0;

	strcpy(medium.questions[43].string , "Which country topped the list in International tourist arrivals in 2017 in South Asian Region?");
    strcpy(medium.options[43][0].string,"Australia");
    strcpy(medium.options[43][1].string,"Bangladesh");
    strcpy(medium.options[43][2].string,"SriLanka");
    strcpy(medium.options[43][3].string,"India");
    medium.correct_ans[43]=3;

	strcpy(medium.questions[44].string , "Shri Yogi Adityanath inaugurated the widows' home 'Krishna Kutir' in which city?");
    strcpy(medium.options[44][0].string,"Lucknow");
    strcpy(medium.options[44][1].string,"Gorakhpur");
    strcpy(medium.options[44][2].string,"Kanpur");
    strcpy(medium.options[44][3].string,"Mathura");
    medium.correct_ans[44]=3;
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
    for(int i=0;i<45;i++)
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
    filepointer = fopen("KBC_QBM.bin", "w");
    if (filepointer == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    //The array defined inside struct is a constant type, and can't be initialised,
    //hence only operations can be used to change its content

    QUESTIONS();

    fwrite (&medium, sizeof(Q_paper1), 1, filepointer);
    CHECK();
    fclose(filepointer);
    // close file
    filepointer=fopen("KBC_QBM.bin","r");
    fread (&RANdom, sizeof(Q_paper1), 1, filepointer);
    PRINT();
    fclose (filepointer);

    return 0;
}

