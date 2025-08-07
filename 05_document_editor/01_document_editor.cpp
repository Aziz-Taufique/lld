#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class DocumentEditor
{
private:
    std::vector<std::string> documentElements;
    std::string renderedDocument;

public:
    void addText(std::string text)
    {
        documentElements.push_back(text);
    };

    void addImage(std::string imgPath)
    {
        documentElements.push_back(imgPath);
    }

    std::string renderDocument()
    {
        if (renderedDocument.empty())
        {
            std::string result;
            for (std::string it : documentElements)
            {
                if (it.length() > 4 && (it.substr(it.length() - 4) == ".jpg" || it.substr(it.size() - 4) == ".png"))
                {
                    result += "[Image: " + it + "]" + "\n";
                }
                else
                {
                    result += it + "\n";
                }
            }
            renderedDocument = result;
        }
        return renderedDocument;
    }

    void saveToFile()
    {
        std::ofstream file("document.txt");

        if (file.is_open())
        {
            file << renderDocument();
            file.close();
            std::cout << "Document saved to document.txt file" << std::endl;
        }
        else
        {
            std::cout << "Error: Unable to open file for writing." << std::endl;
        }
    }
};

int main()
{
    DocumentEditor *docEditor = new DocumentEditor();
    docEditor->addText("I am aziz");
    docEditor->addImage("picture.png");
    docEditor->addText("hitler zinda hai");
    docEditor->renderDocument();
    docEditor->saveToFile();
    return 0;
}