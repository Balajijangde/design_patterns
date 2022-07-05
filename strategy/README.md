# Strategy pattern

## Problem

Suppose we are building a image storage class which stores image and we can compress image or apply any filter before saving it so we roughly come up with below code

```cpp
class ImageStorage{
    void saveFile(string FileName, string compressor, string filter){
        // Applying compressor

        if(compressor == "JPEG"){
            cout <<"Applying JPEG compressor";
        }else if(compressor == "PNG"){
            cout <<"Applying PNG compressor";
        }

        //Applying filter
        if(filter == "blackAndWhite"){
            cout<<"Applying black and white filter";
        }else if(filter == "contrast"){
            cout <<"Applying contrast filter";
        }

        //Saving image
        cout <<"Saving image finally";

    }
}
```

Problem in the above approach is, we are breaking single responsibility principle here and if we add more compressor or filter then we need to make modifications here.

## Solution

So we can use Strategy pattern, Make a interface for compressor and filter and create concrete imlementation for compressor and filter so class diagram will look like.

![](https://media.geeksforgeeks.org/wp-content/uploads/classss.jpg)
