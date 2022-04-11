#include <iostream>
#include "Playlist.h"
using namespace std;

void PrintMenu(string);
void AddSong(PlaylistNode*&, PlaylistNode*&);
void RemoveSong(PlaylistNode*&, PlaylistNode*&);
void ChangePosition(PlaylistNode*&, PlaylistNode*&);
void SpecificArtist(PlaylistNode*);
void TotalTime(PlaylistNode*);
void FullPlaylist(PlaylistNode*);

 
int main()
{
    string title;

    cout << "Enter playlist's title:" << endl;
    getline(cin, title);
    cout << endl;

    PrintMenu(title);

    return 0;
}

void PrintMenu(string title)
{
    char input;
    // Playlist music;
    PlaylistNode* head = nullptr;
    PlaylistNode* tail = nullptr;


    cout << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;

    cin >> input;
    cin.ignore();
    while (input != 'q')
    {
        if (input == 'a')
        {
            // music.AddSong();
            AddSong(head, tail); 
            cout << endl;          
        }
        else if (input == 'd')
        {
            // music.RemoveSong();
            RemoveSong(head, tail);
        }
        else if (input == 'c')
        {
            // music.ChangePosition();
            ChangePosition(head, tail);
        }
        else if (input == 's')
        {
            // music.SpecificArtist();
            SpecificArtist(head);
        }
        else if (input == 't')
        {
            // music.TotalTime();
            TotalTime(head);
        }
        else if (input == 'o')
        {

            // music.FullPlaylist(title);
            cout << title << " - OUTPUT FULL PLAYLIST" << endl;
            FullPlaylist(head);
        }
        
        cout << title << " PLAYLIST MENU" << endl;
        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit" << endl;
        cout << endl;
        cout << "Choose an option:" << endl;

        cin >> input;
        cin.ignore();
        
    }

}

void AddSong(PlaylistNode*& head, PlaylistNode*& tail)
//void Playlist::AddSong()
{
    string ID;
    string name;
    string artist;
    int length;
    cout << "ADD SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    getline(cin, ID);
    cout << "Enter song's name:" << endl;
    getline(cin, name);
    cout << "Enter artist's name:" << endl;
    getline(cin, artist);
    cout << "Enter song's length (in seconds):" << endl;
    cin >> length;

    PlaylistNode *newSong = new PlaylistNode(ID, name, artist, length);
    
    if (head == nullptr)
    {
        head = newSong;
        tail = head;
    }
    else
    {
        tail->SetNext(newSong);
        tail = newSong;
    }
}

void RemoveSong(PlaylistNode*& head, PlaylistNode*& tail)
//void Playlist::RemoveSong()
{
    string ID;
    cout << "REMOVE SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin >> ID;

    PlaylistNode *follow = head;
    PlaylistNode *found = nullptr;
    for (PlaylistNode *curr = head; curr != nullptr; curr = curr->GetNext())
    {
        if (curr->GetID() == ID)
        {
            found = curr;
            break;
        }
        if (curr != follow)
        {
            follow = follow->GetNext();
        }
    }


    if (found != nullptr)
    {
        if (found == head)
        {
            if (found == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->GetNext();
            }     

        }
        else
        {
            follow->SetNext(found->GetNext());
            if (found->GetNext() == nullptr)
            {
                tail = follow;
            }
        } 
        delete found;
    }

    cout << "\"" << found->GetSongName() << "\" removed." << endl << endl;

}

void ChangePosition(PlaylistNode*& head, PlaylistNode*& tail)
// void Playlist::ChangePosition()
{
    int curr;
    int newPos;
    cout << "CHANGE POSITION OF SONG" << endl;
    cout << "Enter song's current position:" << endl;
    cin >> curr;
    cout << "Enter new position for song:" << endl;
    cin >> newPos;

    int totalNodes = 0;
    for (PlaylistNode* i = head; i != nullptr; i = i->GetNext())
    {
        ++totalNodes;
    }

    if ((curr == newPos) || (newPos > totalNodes))
    {
        return;
    }

    PlaylistNode* loc = head;
    PlaylistNode *follow = head;
    for (int i = 1 ; i < curr; ++i)
    {
        if (loc != follow)
        {
            follow = follow->GetNext();
        }
        loc = loc->GetNext();
    }

    PlaylistNode* change = head;
    if (curr > newPos)
    {
        for (int i = 1; i < newPos - 1; ++i)
        {
            change = change->GetNext(); 
        }
    }
    else
    {
        for (int i = 1; i < newPos; ++i)
        {
            change = change->GetNext(); 
        }
    }
    
    


    // //Remove from position
    if (loc == follow)
    {
        head = loc->GetNext(); 
    }
    else
    {
        follow->SetNext(loc->GetNext());
    }

     if (loc == tail)
    {
        tail = follow;
    }


    //Insert to Position
    if (newPos == 1)
    {
        head = loc;
        loc->SetNext(change);
    }
    else
    {
        change->InsertAfter(loc);
    }

    cout << "\"" << loc->GetSongName() << "\" moved to position " << newPos << endl << endl;
}

void SpecificArtist(PlaylistNode* head)
// void Playlist::SpecificArtist()
{
    string artist;
    cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
    cout << "Enter artist's name:" << endl;
    getline(cin, artist);
    cout << endl;

    PlaylistNode* curr;
    int counter = 1;
    for (curr = head; curr != nullptr; curr = curr->GetNext())
    {
        if (curr->GetArtistName() == artist)
        {
            cout << counter << "." << endl;
            curr->PrintPlaylistNode();
            cout << endl;
        }
        
        ++counter;
    }

}

void TotalTime(PlaylistNode* head)
// void Playlist::TotalTime()
{
    int total = 0;
    PlaylistNode* curr;
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
    for (curr = head; curr != nullptr; curr = curr->GetNext())
    {
        total += curr->GetSongLength();
    }
    cout << "Total time: " << total << " seconds" << endl << endl;
}

void FullPlaylist(PlaylistNode* head)
// void Playlist::FullPlaylist(string title)
{
    if (head == nullptr)
    {
        cout << "Playlist is empty" << endl << endl;
    }
    else
    {
        PlaylistNode* curr;
        int counter = 1;
        for (curr = head; curr != nullptr; curr = curr->GetNext())
        {
            cout << counter << "." << endl;
            curr->PrintPlaylistNode();
            cout << endl;
            ++counter;
        }
    }
}