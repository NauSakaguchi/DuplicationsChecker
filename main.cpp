#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const static int NUMBER = 0;
const static int MGI_SYMBOL = 1;
const static int HGNC_SYMBOL = 2;
const static int CHROMOSOME = 3;
const static int GENE = 4;
const static int ROWSIZE= 4;
const static int GENE_COLUMN_SIZE= 3;
const static int GENE_ROW_SIZE= 14003;
const static int MALE_ROW_SIZE= 16273;
//const static int MALE_ROW_SIZE= 20;

using namespace std;



int main() {

    int counter = 0;
    vector<string> names;
    string geneArray1[3];
    string geneArray2[3];
    string str;
    bool Flag = false;

    ofstream outputfile("../Dataset/dupulicationsList.txt");

    ifstream ifile_gene1("../Dataset/geneAnnotation2.csv");
    if(ifile_gene1.fail()){
        cerr << "Failed to open file." << endl;
        return -1;
    }

    ifstream ifile_gene2("../Dataset/geneAnnotation2.csv");
    if(ifile_gene2.fail()){
        cerr << "Failed to open file." << endl;
        return -1;
    }
    getline(ifile_gene2, geneArray2[NUMBER], ',');
    getline(ifile_gene2, geneArray2[MGI_SYMBOL], ',');
    getline(ifile_gene2, geneArray2[HGNC_SYMBOL]);

    for(int i = 1; i < 14002; i++){
        getline(ifile_gene1, geneArray1[NUMBER], ',');
        getline(ifile_gene1, geneArray1[MGI_SYMBOL], ',');
        getline(ifile_gene1, geneArray1[HGNC_SYMBOL]);

        getline(ifile_gene2, geneArray2[NUMBER], ',');
        getline(ifile_gene2, geneArray2[MGI_SYMBOL], ',');
        getline(ifile_gene2, geneArray2[HGNC_SYMBOL]);

        if(geneArray1[MGI_SYMBOL] == geneArray2[MGI_SYMBOL]){
            str = geneArray1[HGNC_SYMBOL];
            str = str + ' ' + geneArray1[NUMBER];
            names.push_back(str);
            counter++;
            Flag = true;
        }else if(geneArray1[MGI_SYMBOL] != geneArray2[MGI_SYMBOL] && Flag){
            str = geneArray1[HGNC_SYMBOL];
            str = str + ' ' + geneArray1[NUMBER];
            names.push_back(str);
            outputfile << geneArray1[MGI_SYMBOL] << ":" << endl;
            for(auto i : names){
                outputfile << '\t' <<  i << endl;
            }

            Flag = false;
            names.clear();
        }else{

        }
    }


    //cout << geneArray2[0] << ' ' << geneArray2[1] << ' ' << geneArray2[2];

    outputfile << "Total: " << counter << endl;

    return 0;
}
