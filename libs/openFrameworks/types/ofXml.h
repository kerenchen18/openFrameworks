
#pragma once

#include "ofMain.h"

#include <numeric>

#include <Poco/DOM/Document.h>
#include <Poco/DOM/DocumentFragment.h>
#include <Poco/DOM/Element.h>
#include <Poco/DOM/DOMParser.h>

#include <Poco/DOM/DOMException.h>
#include <Poco/SAX/SAXException.h>
#include <Poco/XML/XMLString.h>
#include <Poco/XML/XMLWriter.h>
#include <Poco/DOM/DOMParser.h>
#include <Poco/DOM/DOMWriter.h>
#include <Poco/DOM/Document.h>
#include <Poco/DOM/Attr.h>
#include <Poco/DOM/Node.h>
#include <Poco/DOM/Text.h>
#include <Poco/DOM/NodeIterator.h>
#include <Poco/DOM/NodeFilter.h>
#include <Poco/DOM/NamedNodeMap.h>  
#include <Poco/DOM/ChildNodesList.h>

using namespace Poco::XML;

class ofXml {
    
public:
    
    ofXml();
    ~ofXml();
    
    ofXml( const ofXml& rhs );
    const ofXml& operator =( const ofXml& rhs );
    
    bool            addValue(const string& path, const string& value, bool createEntirePath = false);
    bool            addChild( const string& path );
    
    string          getValue(const string& path);
    string          getValue();
    bool            setValue(const string& path, const string& value);
    
    string          getAttribute(const string& path);
    //bool            addAttribute(const string& path, const string& value);
    bool            setAttribute(const string& path, const string& value);
    
    bool            clearAttributes(const string& path);
    bool            clearContents(const string& path);
    bool            clearContents();
    bool            clearAttributes();
    
    bool            remove(const string& path); // works for both attributes and tags
    bool            removeAll(const string& path); // works for both attributes and tags
    bool            exists(const string& path); // works for both attributes and tags
    
    bool            setCurrentElement(const string& path);
    string          getCurrentElementName();
    bool            resetCurrentElement();
    
    bool            setCurrentElementToParent();
    bool            setCurrentElementToParent(int numLevelsUp);
    
    bool            setCurrentElementToSibling();
    bool            setCurrentElementToPrevSibling();
    
    void            copyXmlToString(string & str);
    bool            loadFromBuffer( string buffer );
    int             getNumChildren();
    
    void            addXml( ofXml& xml );
    
    map<string, string> getAttributes();
    string toString();
    
    Element*        getCurrentElement();
    Element*        getElement(const string& path);
    
    Document*       getDocument();
    Document*       getDocument() const;

       
protected:
    
    //void addList( Element *addTo, Element *addFrom, vector<Element*>& toBeReleased);
    //void addList( Element *addTo, Element *addFrom);
    
    string DOMErrorMessage(short msg);
    
    Poco::XML::Document *document;
    Element *element;
    
};
