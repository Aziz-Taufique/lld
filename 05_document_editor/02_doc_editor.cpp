#include <iostream>
#include <vector>
#include <fstream>

class DocumentElement
{
public:
    virtual std::string render() = 0;
};

class TextElement : public DocumentElement
{
private:
    std::string text;

public:
    TextElement(std::string text)
    {
        this->text = text;
    };

    std::string render() override
    {
        return text;
    }
};

class ImageElement : public DocumentElement
{
private:
    std::string imagePath;

public:
    ImageElement(std::string imagePath)
    {
        this->imagePath = imagePath;
    }

    std::string render() override
    {
        return "[Image: " + imagePath + "]";
    }
};

class NewLineElement : public DocumentElement
{
public:
    std::string render() override
    {
        return "\n";
    }
};

class TabElement : public DocumentElement
{
public:
    std::string render() override
    {
        return "\t";
    }
};

class Document
{
private:
    std::vector<DocumentElement *> documentElements;

public:
    void addElement(DocumentElement *element)
    {
        documentElements.push_back(element);
    }

    std::string render()
    {
        std::string result;
        for (auto it : documentElements)
        {
            result += it->render();
        }
        return result;
    }
};

class Persistance
{
public:
    virtual void save(std::string data, std::string fileName) = 0;
};

class FileStorage : public Persistance
{
public:
    void save(std::string data, std::string fileName) override
    {
        std::ofstream outFile(fileName);

        if (outFile.is_open())
        {
            outFile << data;
            outFile.close();
            std::cout << "Document saved to Document2.txt file" << std::endl;
        }
        else
        {
            std::cout << "Error: Unable to open file for writing" << std::endl;
        }
    }
};

class DbStorage : public Persistance
{
public:
    void save(std::string data, std::string fileName) override
    {
        // save to db;

        std::cout << "Document saved to database" << std::endl;
    }
};

class DocumentEditor
{
private:
    Document *document;
    Persistance *storage;
    std::string renderedDocument;

public:
    DocumentEditor(Document *document, Persistance *storage)
    {
        this->document = document;
        this->storage = storage;
    }

    void addText(std::string text)
    {
        document->addElement(new TextElement(text));
    }

    void addImage(std::string imagePath)
    {
        document->addElement(new ImageElement(imagePath));
    }

    void addNewLine()
    {
        document->addElement(new NewLineElement());
    }

    void addTabSpace()
    {
        document->addElement(new TabElement());
    }

    std::string renderDocument()
    {
        if (renderedDocument.empty())
        {
            renderedDocument = document->render();
        }
        return renderedDocument;
    }

    void saveDocument(std::string fileName)
    {
        storage->save(renderDocument(), fileName);
    }
};

int main()
{

    Document *document = new Document();
    Persistance *persistance = new FileStorage();

    DocumentEditor *editor = new DocumentEditor(document, persistance);

    editor->addText("I am text");
    editor->addNewLine();
    editor->addImage("picture2.txt");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("heroin ho heroin");
    std::cout << editor->renderDocument() << std::endl;
    editor->saveDocument("Document2.txt");

    std::cout << "---------------------------------------------------------" << std::endl;

    Document *document2 = new Document();
    Persistance *persistance2 = new FileStorage();

    DocumentEditor *editor2 = new DocumentEditor(document2, persistance2);

    editor2->addText("I am text 2");
    editor2->addNewLine();
    editor2->addImage("picture3.txt");
    editor2->addNewLine();
    editor2->addTabSpace();
    editor2->addText("as;fjasdfafas");
    std::cout << editor2->renderDocument() << std::endl;
    editor2->saveDocument("Document3.txt");

    return 0;
}