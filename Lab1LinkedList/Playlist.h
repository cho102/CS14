#include <iostream>
#include <string>
using namespace std;

#ifndef PLAYLIST_H
#define PLAYLIST_H

// class Playlist
// {
//     public: 
//         void AddSong();
//         void RemoveSong();
//         void ChangePosition();
//         void SpecificArtist();
//         void TotalTime();
//         void FullPlaylist(string);

//     private:
//         PlaylistNode* head;
//         PlaylistNode* tail;
// };

class PlaylistNode {
    public:
        PlaylistNode();
        PlaylistNode(string, string, string, int); //parameterized constructor
        void InsertAfter(PlaylistNode*&);
        void SetNext(PlaylistNode*); //- Mutator (1 pt)
        string GetID(); //- Accessor
        string GetSongName(); //- Accessor
        string GetArtistName(); //- Accessor
        int GetSongLength(); //- Accessor
        PlaylistNode *GetNext(); //- Accessor
        void PrintPlaylistNode();
    
    private: 
        string uniqueID; // - Initialized to "none" in default constructor
        string songName; // - Initialized to "none" in default constructor
        string artistName; // - Initialized to "none" in default constructor
        int songLength; // - Initialized to 0 in default constructor
        PlaylistNode* nextNodePtr; // - Initialized to 0 in default constructor

};

#endif