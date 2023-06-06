namespace tinyxml2 {
    class XMLElement;
    class XMLDocument;
}

/**
 * @brief Loads and stores config metadata
 *
 * Loads from config.xml the configuration metadata such as the
 * type of tracker, the input video name, the ouput path,
 * whether to save bboxes or the video, etc.
 */
class Metadata {
public:

    /**
     * @brief Read config.xml and populate
     * 
     * config.xml is loaded and the private variables are
     * populated. These are then available with help of getters
     * 
     */
    Metadata();

    /**
     * @brief Get the output path folder
     * 
     * @return Location of the output folder
     */
    const char* GetOutPath() { return this->outPath_; };
    /**
     * @brief Get the path of the input video file
     * 
     * @return File name with extension of the video
     */
    const char* GetVideoPath() { return this->videoFile_; };

    /**
     * @brief Get the output filename for the bbox text file
     * 
     * @return Filename with extension for the bounding boxes
     */
    const char* GetBboxPath() { return this->bboxFile_; };

    /**
     * @brief Get tracker type from config.xml
     * 
     * @return String of the tracker's name
     */
    const char* GetTrackerType() { return this->trackerType_; };

    /**
     * @brief Boolean whether the video output has to be saved
     * 
     * @return true: save output video
     * @return false: do not save output video
     */
    bool ShouldSaveVideo() { return this->saveVideo_; };

    /**
     * @brief Wheter to save the output bounding boxes
     * 
     * @return true: save bounding boxes in a text file
     * @return false: not save bounding boxes
     */
    bool ShouldSaveBbox() { return this->saveBbox_; };

    /**
     * @brief Print in the command line all information
     * 
     * The informations contained in config.xml are nicely
     * printed in the console.
     * 
     */
    void Recap();

private:
    /**
     * @brief Path of the output folder
     * 
     */
    const char* outPath_;

    /**
     * @brief Name with extension of input video
     * 
     */
    const char* videoFile_;

    /**
     * @brief Name with extension of output boundinx boxes
     * 
     */
    const char* bboxFile_;

    /**
     * @brief ID name of the tracker type to apply
     * 
     */
    const char* trackerType_;

    /**
     * @brief Whether to save the output video
     * 
     */
    bool saveVideo_;

    /**
     * @brief Whether to save the output boundinx boxes
     * 
     */
    bool saveBbox_;

    /**
     * @brief Verify video and tracker tag
     * 
     * The video tag has to contain an input file 
     * attribute and the tracker the type attribute
     * 
     * @param el The root XML element (first doc child)
     */
    void VerifyElement_(tinyxml2::XMLElement* el);

    /**
     * @brief Parse the xml document
     * 
     * Extract all text datas needed for the sw such as
     * output/input file names and other parameters
     * 
     * @param doc XML tinyxml2 object
     */
    void Parse_(tinyxml2::XMLDocument& doc);
};