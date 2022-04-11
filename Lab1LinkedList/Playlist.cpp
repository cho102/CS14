#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;

PlaylistNode::PlaylistNode()
{
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}

//parameterized constructor
PlaylistNode::PlaylistNode(string ID, string song, string artist, int length)
{
    uniqueID = ID;
    songName = song;
    artistName = artist;
    songLength = length;
    nextNodePtr = nullptr;
} 


void PlaylistNode::InsertAfter(PlaylistNode*& temp)
{
    PlaylistNode* holder = this->GetNext();
    this->SetNext(temp);
    temp->SetNext(holder);

}

//- Mutator (1 pt)
void PlaylistNode::SetNext(PlaylistNode* next)
{
        nextNodePtr = next;   
} 

//- Accessor
string PlaylistNode::GetID()
{
    return uniqueID;
} 

//- Accessor
string PlaylistNode::GetSongName()
{
    return songName;
} 

//- Accessor
string PlaylistNode::GetArtistName()
{
    return artistName;
}


//- Accessor
int PlaylistNode::GetSongLength()
{
    return songLength;
} 

//- Accessor
PlaylistNode* PlaylistNode::GetNext()
{
    return nextNodePtr;
} 


void PlaylistNode::PrintPlaylistNode()
{
    cout << "Unique ID: " << GetID() << endl;
    cout << "Song Name: " << GetSongName() << endl;
    cout << "Artist Name: " << GetArtistName() << endl;
    cout << "Song Length (in seconds): " << GetSongLength() << endl;
}

