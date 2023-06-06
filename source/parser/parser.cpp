#include "parser.h"
#include "../../tinyxml/tinyxml2.h"
#include<stdio.h>
#include<string>

Metadata::Metadata() {
    this->saveBbox_ = false;
    
    // Instantiate xml doc object
    tinyxml2::XMLDocument doc;

    // Check opening
    if (doc.LoadFile("config.xml") != tinyxml2::XML_SUCCESS) {
        printf("[e] Error loading XML file\n");
        exit(1);
    } else
	{
		printf( "[i] Successful read of 'config.xml'.\n");
	}

    // Check if outer tag there
    tinyxml2::XMLElement* ctx = doc.FirstChildElement();
    if (!ctx) {
        printf("[e] Error getting tracking data from XML");
        exit(1);
    } 
    
    // Store output path
    this->outPath_ = ctx->Attribute("outputPath");
    if (!this->outPath_) {
        this->outPath_ = "./";
    }

    // Analyse document
    tinyxml2::XMLElement* child = ctx->FirstChildElement();
    const char* tagName;
    while(child) {
        this->VerifyElement_(child);
        tagName = child->Name();
        if(strcmp(tagName,"video")==0) {
            this->videoFile_ = child->Attribute("name");
            if(strcmp(child->Attribute("save"),"True")==0) {
                this->saveVideo_ = true;
            } else {
                this->saveVideo_ = false;
            }
        } else if(strcmp(tagName,"boundingBox")==0) {
            this->saveBbox_ = true;
            this->bboxFile_ = child->Attribute("name");
            if(!this->bboxFile_) {
                this->bboxFile_ = "boundingbox.txt";
            }
        } else if(strcmp(tagName,"tracker")==0) {
            this->trackerType_ = child->Attribute("type");
        }
        child = child->NextSiblingElement();
    } 
}

void Metadata::VerifyElement_(tinyxml2::XMLElement* el) {
    const char* name = el->Name();
    if(name == "video") {
        const char* file = el->Attribute("file");
        if(!file) {
            printf("[e] No file name for video\n");
            exit(1);
        }
    } else if (name == "tracker") {
        const char* type = el->Attribute("type");
        if(!type) {
            printf("[e] No file type for tracker\n");
            exit(1);
        }
    }
}

void Metadata::Recap() {
    printf("[i] Input video: %s\n",this->GetVideoPath());
    printf("[i] Output folder: %s\n",this->GetOutPath());
    printf(
        "[i] Save video: %s\n",
        (this->ShouldSaveVideo())?"YES":"NO"
    );
    printf(
        "[i] Save bbox: %s\n",
        (this->ShouldSaveBbox())?"YES":"NO"
    );
}