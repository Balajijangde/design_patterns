#include <iostream>

using namespace std;

class ICompressor
{
public:
    virtual void compress(string fileName) = 0;
};
class IFilter
{
public:
    virtual void apply(string filename) = 0;
};
class JPEGCompressor : public ICompressor
{
public:
    void compress(string fileName)
    {
        cout << "Applying JPEG compressor on " << fileName << "\n";
    }
};
class PNGCompressor : public ICompressor
{
public:
    void compress(string fileName)
    {
        cout << "Applying PNG compressor on " << fileName << "\n";
    }
};
class BlackAndWhiteFilter : public IFilter
{
public:
    void apply(string fileName)
    {
        cout << "Applying Black and White filter on " << fileName << "\n";
    }
};
class ContrastFilter : public IFilter
{
public:
    void apply(string fileName)
    {
        cout << "Applying contrast filter on " << fileName << "\n";
    }
};

class ImageStorage
{
public:
    void saveImage(string fileName, ICompressor *compressor, IFilter *filter)
    {
        compressor->compress(fileName);
        filter->apply(fileName);

        cout << "Saving " << fileName << "\n";
    }
};

int main()
{
    ImageStorage *storage = new ImageStorage();
    storage->saveImage("mountains", new JPEGCompressor(), new BlackAndWhiteFilter());
}