#include "editor.h"

Editor::Editor(QWidget *parent) : QTextEdit(parent)
{

}


// ============= Text Editor ======================
void Editor::Write_Code_Text_Editor(vector<string> s)
{
    string PlainText;
// ================= Onther Approach =================
//    for (uint i =0 ; i < s.size(); ++ i)
//    {
//        PlainText + s[i]+ "\n"  ;
//    }
//    this->Code_TextEdit->setPlainText(   QString::fromStdString(PlainText)   );

    // ================= Onther Approach =================
    for (int i =0 ; i<s.size();i++) {

        this->append(QString::fromStdString( s[i] ) );
    }
//    this->Code_TextEdit->undo();  // undo the previews change in text editor
//    this->Code_TextEdit->append("RRRRRRRRRRRR");  // add the string to the end of the text editor
}
vector<string> Editor::Read_Code_Text_Editor()
{
    QString PlainText = this->toPlainText();
    string plaintext = PlainText.toStdString();
    vector<string> instructions =split_string(plaintext,"\n");
    return instructions;}
vector<string> split_string(string s,string splitter)
{
    vector<string> splitted;
    uint n = s.length();
    int pos = 0;
    int start = pos;
    while (pos != string::npos)
    {
        pos = s.find_first_of(splitter,pos+1);
        string splitted_string = s.substr(start,pos-start);
        splitted.push_back(splitted_string);
        start = pos+1;
    }

    return splitted;}
void print(vector<string> x)
{
    for (int i = 0; i < x.size()-1; ++i) {
        cout << x[i] << "-";
    }
    cout << x[x.size()-1] << endl;

}
