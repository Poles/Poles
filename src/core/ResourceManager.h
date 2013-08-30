#ifndef RESOURCEMANAGER_H
#define	RESOURCEMANAGER_H



class ResourceManager {
public:
    
    ResourceManager * instance();

private:
    ResourceManager();
    ~ResourceManager();
    
private:
    static ResourceManager * classInstance;

};

#endif	/* RESOURCEMANAGER_H */

