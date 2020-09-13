#include <iostream>
#include <vector>
#include <chrono>
#include <time.h>
#include <windows.h>
using namespace std;
using namespace std::chrono;

struct stop_and_wait
{
    vector<char>sent;
    vector<char>stored;                     vector<char>stored2;
    vector<char>recieved;                   vector<char>recieved2;
    vector<char>final_message;              vector<char>final_message2;
    int Sn = 0;                             int Sn2 = 0;
    int Rn = 0;                             int Rn2 = 0;
    int ack_number = 0;                     int ack_number2 = 0;
    bool can_send = true;                   bool can_send2 = true;
    bool time_out = false;                  bool time_out2 = false;
    bool request_to_send = true;            bool request_to_send2 = true;
    bool ack_arrival_notification = false;  bool ack_arrival_notification2 = false;
    bool data_arrival_notification = false; bool data_arrival_notification2 = false;

    void wait(void)
    {
        Sleep(100); cout << ".";
        return;
    }
    bool check_for_break1(void)
    {
        for(int i = 0; i < final_message.size(); i++)
            if(final_message[i] == '*')
                return true;
        return false;
    }
    bool check_for_break2(void)
    {
        for(int i = 0; i < final_message2.size(); i++)
            if(final_message2[i] == '*')
                return true;
        return false;
    }
    bool check_for_break(void)
    {
        if(check_for_break1() == true && check_for_break2() == true)
            return true;
        return false;
    }

    void get_data(void)
    {
        //gets the data from the network layer -> here it's user :)
        char input = '#';

        cout << "(Network Layer - Sender Site)\n";
        cout << "Enter the data you want to send (enter * when you are done): ";
        while(input != '*')
        {
            cin >> input;
            sent.push_back(input);
        }
        cout << "\nMaking Frame\n";
    }
    void send_frame(int frame_num)
    {
        //copying the data from the sender vector to the reciever vector :)
        cout << "Sending Frame To Receiver 1";
        wait();
        cout << endl;
        for(int i = frame_num * 10; i < (frame_num * 10) + 10 ; i++)
        {
            if((i / 10) == 0 /*|| (i / 10) == 1 || (i / 10) == 2 || (i / 10) == 3 || (i / 10) == 4 || (i / 10) == 5 || (i / 10) == 6 || (i / 10) == 7 || (i / 10) == 8 || (i / 10) == 9 \
               || (i / 10) == 10 || (i / 10) == 11 || (i / 10) == 12 || (i / 10) == 13 || (i / 10) == 14 || (i / 10) == 15 || (i / 10) == 16 || (i / 10) == 17 || (i / 10) == 18 \
               || (i / 10) == 19 || (i / 10) == 20 || (i / 10) == 21 || (i / 10) == 22 || (i / 10) == 23 || (i / 10) == 24 || (i / 10) == 25 || (i / 10) == 26 || (i / 10) == 27 \
               || (i / 10) == 28 || (i / 10) == 29*/)
            {
                recieved.push_back('-');
                stored.push_back(sent[i]);
            }
            else
                recieved.push_back(sent[i]);
        }
        data_arrival_notification = true;
        if(Sn % 2 == 0)
            cout << "Frame " << 0 << " Sent\n";
        else
            cout << "Frame " << 1 << " Sent\n";
    }
    void send_frame2(int frame_num)
    {
        //copying the data from the sender vector to the reciever vector :)
        cout << "Sending Frame To Receiver 2";
        wait();
        cout << endl;
        for(int i = frame_num * 10; i < (frame_num * 10) + 10 ; i++)
        {
            if((i / 10) == 0 /*|| (i / 10) == 1 || (i / 10) == 2 || (i / 10) == 3 || (i / 10) == 4 || (i / 10) == 5 || (i / 10) == 6 || (i / 10) == 7 || (i / 10) == 8 || (i / 10) == 9 \
               || (i / 10) == 10 || (i / 10) == 11 || (i / 10) == 12 || (i / 10) == 13 || (i / 10) == 14 || (i / 10) == 15 || (i / 10) == 16 || (i / 10) == 17 || (i / 10) == 18 \
               || (i / 10) == 19 || (i / 10) == 20 || (i / 10) == 21 || (i / 10) == 22 || (i / 10) == 23 || (i / 10) == 24 || (i / 10) == 25 || (i / 10) == 26 || (i / 10) == 27 \
               || (i / 10) == 28 || (i / 10) == 29*/)
            {
                recieved2.push_back('-');
                stored2.push_back(sent[i]);
            }
            else
                recieved2.push_back(sent[i]);
        }
        data_arrival_notification2 = true;
        if(Sn2 % 2 == 0)
            cout << "Frame " << 0 << " Sent\n";
        else
            cout << "Frame " << 1 << " Sent\n";
    }
    void send_frame_again(int frame_num)
    {
        //copying the data from the sender vector to the reciever vector :)
        cout << "Sending Frame To Receiver 1";
        wait();
        cout << endl;

        int j = frame_num * 10;
        for(int i = 0; i < stored.size(); i++)
        {
            recieved[j] = stored[i];
            j++;
        }
        data_arrival_notification = true;
        if((Sn - 1) % 2 == 0)
            cout << "Frame " << 0 << " Sent Again\n";
        else
            cout << "Frame " << 1 << " Sent Again\n";
        stored.clear();
    }
    void send_frame_again2(int frame_num)
    {
        //copying the data from the sender vector to the reciever vector :)
        cout << "Sending Frame To Receiver 2";
        wait();
        cout << endl;

        int j = frame_num * 10;
        for(int i = 0; i < stored2.size(); i++)
        {
            recieved2[j] = stored2[i];
            j++;
        }
        data_arrival_notification2 = true;
        if((Sn2 - 1) % 2 == 0)
            cout << "Frame " << 0 << " Sent Again\n";
        else
            cout << "Frame " << 1 << " Sent Again\n";
        stored2.clear();
    }
    void recieve_ack(int ack_num)
    {
        ack_number = ack_num;
    }
    void recieve_ack2(int ack_num)
    {
        ack_number2 = ack_num;
    }

    void send_ack(int ack_num)
    {
        cout << "\nSending acknowledge from Receiver 1 to the Sender Site";
        if(ack_num % 2 == 0)
            cout << "\nack number: " << 0 << "\n\n";
        else
            cout << "\nack number: " << 1 << "\n\n";
        ack_number = ack_num;
        request_to_send = true;
        ack_arrival_notification = true;
    }
    void send_ack2(int ack_num)
    {
        cout << "\nSending acknowledge from Receiver 2 to the Sender Site";
        if(ack_num % 2 == 0)
            cout << "\nack number: " << 0 << "\n\n";
        else
            cout << "\nack number: " << 1 << "\n\n";
        ack_number2 = ack_num;
        request_to_send2 = true;
        ack_arrival_notification2 = true;
    }
    void deliver_data(int frame_num)
    {
        cout << "\n(Reciever 1 Site)\n";
        cout << "We have recieved the following data: ";

        for(int i = frame_num * 10; i < (frame_num * 10) + 10; i++)
        {
            final_message.push_back(recieved[i]);
            if(recieved[i] == '*')
                break;
        }
        for(int i = 0; i < final_message.size(); i++)
            cout << final_message[i];
        cout << endl;
    }
    void deliver_data2(int frame_num)
    {
        cout << "\n(Reciever 2 Site)\n";
        cout << "We have recieved the following data: ";

        for(int i = frame_num * 10; i < (frame_num * 10) + 10; i++)
        {
            final_message2.push_back(recieved2[i]);
            if(recieved2[i] == '*')
                break;
        }
        for(int i = 0; i < final_message2.size(); i++)
            cout << final_message2[i];
        cout << endl;
    }
    bool corrupted_frame(vector<char>frame)
    {
        for(int i = 0; i < frame.size(); i++)
        {
            if(frame[i] == '-') //if any of the recieved elements is '-' -> assume corrupted
                return true; //corrupted frame (packet loss)
        }
        return false;
    }
};
struct go_back_n
{
    vector<char>stored;
    vector<char>recieved;                   vector<char>recieved2;
    vector<char>final_message;              vector<char>final_message2;
    int Sw = 4;                             int Sw2 = 4;
    int Sf = 0;                             int Sf2 = 0;
    int Sn = 0;                             int Sn2 = 0;
    int Rn = 0;                             int Rn2 = 0;
    int ack_number = 0;                     int ack_number2 = 0;
    bool request_to_send = true;            bool request_to_send2 = true;
    bool time_out = false;                  bool time_out2 = false;
    bool ack_arrival_notification = false;  bool ack_arrival_notification2 = false;
    bool data_arrival_notification = false; bool data_arrival_notification2 = false;

    bool check_for_break1(void)
    {
        for(int i = 0; i < final_message.size(); i++)
            if(final_message[i] == '*')
                return true;
        return false;
    }
    bool check_for_break2(void)
    {
        for(int i = 0; i < final_message2.size(); i++)
            if(final_message2[i] == '*')
                return true;
        return false;
    }
    bool check_for_break(void)
    {
        if(check_for_break1() == true && check_for_break2() == true)
            return true;
        return false;
    }

    void get_data(void)
    {
        //gets the frame from the network layer -> here it's user :)
        char input = '#';

        cout << "(Network Layer - Sender Site)\n";
        cout << "Window size = 4 and Frame size = 10, You must enter at least 41 bits to have error correction in packet losses.\n";
        cout << "Enter the data you want to send (enter * when you are done): ";
        while(input != '*')
        {
            cin >> input;
            stored.push_back(input);
        }
        cout << "\nMaking Frame\n";
    }
    void send_frame(int frame_num)
    {
        cout << "Sending Frame To Receiver 1\n";
        for(int i = frame_num * 10; i < (frame_num * 10) + 10 ; i++)
        {
            if((i / 10) == 0 /*|| (i / 10) == 1 || (i / 10) == 2 || (i / 10) == 3 || (i / 10) == 4 || (i / 10) == 5 || (i / 10) == 6 || (i / 10) == 7 || (i / 10) == 8 || (i / 10) == 9 \
               || (i / 10) == 10 || (i / 10) == 11 || (i / 10) == 12 || (i / 10) == 13 || (i / 10) == 14 || (i / 10) == 15 || (i / 10) == 16 || (i / 10) == 17 || (i / 10) == 18 \
               || (i / 10) == 19 || (i / 10) == 20 || (i / 10) == 21 || (i / 10) == 22 || (i / 10) == 23 || (i / 10) == 24 || (i / 10) == 25 || (i / 10) == 26 || (i / 10) == 27*/)
            {
                recieved.push_back('-');
            }
            else
                recieved.insert(recieved.begin() + i, stored[i]);
        }
        data_arrival_notification = true;
        int iterator = Sn / 5;
        cout << "Frame " << Sn - (5 * iterator) << " Sent\n";
    }
    void send_frame2(int frame_num)
    {
        cout << "Sending Frame To Receiver 2\n";
        for(int i = frame_num * 10; i < (frame_num * 10) + 10 ; i++)
        {
            if((i / 10) == 0 /*|| (i / 10) == 1 || (i / 10) == 2 ||(i / 10) == 3 || (i / 10) == 4 || (i / 10) == 5 || (i / 10) == 6 || (i / 10) == 7 || (i / 10) == 8 || (i / 10) == 9 \
               || (i / 10) == 10 || (i / 10) == 11 || (i / 10) == 12 || (i / 10) == 13 || (i / 10) == 14 || (i / 10) == 15 || (i / 10) == 16 || (i / 10) == 17 || (i / 10) == 18 \
               || (i / 10) == 19 || (i / 10) == 20 || (i / 10) == 21 || (i / 10) == 22 || (i / 10) == 23 || (i / 10) == 24 || (i / 10) == 25 || (i / 10) == 26 || (i / 10) == 27*/)
            {
                recieved2.push_back('-');
            }
            else
                recieved2.insert(recieved2.begin() + i, stored[i]);
        }
        data_arrival_notification2 = true;
        int iterator = Sn2 / 5;
        cout << "Frame " << Sn2 - (5 * iterator) << " Sent\n";
    }
    void send_frame_again(int frame_num)
    {
        cout << "Sending Frame To Receiver 1\n";
        int j = frame_num * 5;
        for(int i = 10 * frame_num; i < (10 * frame_num) + 10 ; i++)
        {
            recieved[i] = stored[i];
            j++;
        }
        int iterator = frame_num / 5;
        cout << "Frame " << frame_num - (5 * iterator) << " Sent Again\n";
    }
    void send_frame_again2(int frame_num)
    {
        cout << "Sending Frame To Receiver 2\n";
        int j = frame_num * 10;
        for(int i = 10 * frame_num; i < (10 * frame_num) + 10 ; i++)
        {
            recieved2[i] = stored[i];
            j++;
        }
        int iterator = frame_num / 5;
        cout << "Frame " << frame_num - (5 * iterator) << " Sent Again\n";
    }
    void recieve_ack(int ack_num)
    {
        cout << "\nRecieved acknowledge from the Reciever 1 Site\n";
        int iterator = ack_num / 5;
        cout << "ack_number: " << ack_num - (5 * iterator) << "\n";
    }
    void recieve_ack2(int ack_num)
    {
        cout << "\nRecieved acknowledge from the Reciever 2 Site\n";
        int iterator = ack_num / 5;
        cout << "ack_number: " << ack_num - (5 * iterator) << "\n";
    }

    void deliver_data(int frame_num)
    {
        cout << "\n(Reciever 1 Site)\n";
        cout << "We have recieved the following data: ";
        for(int i = frame_num * 10; i < (frame_num * 10) + 10; i++)
        {
            final_message.push_back(recieved[i]);
            if(recieved[i] == '*')
                break;
        }
        for(int i = 0; i < final_message.size(); i++)
            cout << final_message[i];
        cout << endl;
    }
    void deliver_data2(int frame_num)
    {
        cout << "\n(Reciever 2 Site)\n";
        cout << "We have recieved the following data: ";
        for(int i = frame_num * 10; i < (frame_num * 10) + 10; i++)
        {
            final_message2.push_back(recieved2[i]);
            if(recieved2[i] == '*')
                break;
        }
        for(int i = 0; i < final_message2.size(); i++)
            cout << final_message2[i];
        cout << endl;
    }
    void correct_data(int frame_num)
    {
        int j = frame_num * 10;
        for(int i = frame_num * 10; i < (frame_num * 10) + 10; i++)
        {
            final_message[j] = stored[i];
            j++;
            if(recieved[i] == '*')
                break;
        }
    }
    void correct_data2(int frame_num)
    {
        int j = frame_num * 10;
        for(int i = frame_num * 10; i < (frame_num * 10) + 10; i++)
        {
            final_message2[j] = stored[i];
            j++;
            if(recieved2[i] == '*')
                break;
        }
    }
    void send_ack(int ack_num)
    {
        cout << "\nSending acknowledge from Receiver 1 to the Sender Site";
        int iterator = ack_num / 5;
        cout << "\nack number " << ack_num - (5 * iterator) << "\n\n";
        ack_number = ack_num;
        ack_arrival_notification = true;
    }
    void send_ack2(int ack_num)
    {
        cout << "\nSending acknowledge from Receiver 2 to the Sender Site";
        int iterator = ack_num / 5;
        cout << "\nack number " << ack_num - (5 * iterator) << "\n\n";
        ack_number2 = ack_num;
        ack_arrival_notification2 = true;
    }
    bool corrupted_frame(vector<char>frame)
    {
        for(int i = 0; i < frame.size(); i++)
        {
            if(frame[i] == '-') //if any of the recieved elements is '-' -> assume corrupted
                return true; //corrupted frame (packet loss)
        }
        return false;
    }
};
struct selective_repeat
{
    vector<char>stored;
    vector<char>recieved;                   vector<char>recieved2;
    vector<char>final_message;              vector<char>final_message2;
    vector<bool>marked;                     vector<bool>marked2;
    int Sw = 4;                             int Sw2 = 4;
    int Sf = 0;                             int Sf2 = 0;
    int Sn = 0;                             int Sn2 = 0;
    int Rn = 0;                             int Rn2 = 0;
    int ack_number = 0;                     int ack_number2 = 0;
    bool time_out = false;                  bool time_out2 = false;
    bool time_out_0 = false;                bool time_out_02 = false;
    bool time_out_1 = false;                bool time_out_12 = false;
    bool time_out_2 = false;                bool time_out_22 = false;
    bool time_out_3 = false;                bool time_out_32 = false;
    bool ack_needed = false;                bool ack_needed2 = false;
    bool request_to_send = true;            bool request_to_send2 = true;
    bool ack_arrival_notification = false;  bool ack_arrival_notification2 = false;
    bool data_arrival_notification = false; bool data_arrival_notification2 = false;

    void build_vector(void)
    {
        marked.resize(100); marked2.resize(100);
        for(int i = 0; i < marked.size(); i++)
        {
            marked[i] = false;
            marked2[i] = false;
        }
    }
    bool check_for_break1(void)
    {
        for(int i = 0; i < final_message.size(); i++)
            if(final_message[i] == '*')
                return true;
        return false;
    }
    bool check_for_break2(void)
    {
        for(int i = 0; i < final_message2.size(); i++)
            if(final_message2[i] == '*')
                return true;
        return false;
    }
    bool check_for_break(void)
    {
        if(check_for_break1() == true && check_for_break2() == true)
            return true;
        return false;
    }

    void get_data(void)
    {
        char input = '#';

        cout << "(Network Layer - Sender Site)\n";
        cout << "Window size = 4 and Frame size = 10, You must enter at least 41 bits to have error correction in packet losses.\n";
        cout << "Enter the data you want to send (enter * when you are done): ";
        while(input != '*')
        {
            cin >> input;
            stored.push_back(input);
        }
        cout << "\nMaking Frame\n";
    }
    void send_frame(int frame_num)
    {
        cout << "Sending Frame To Receiver 1\n";
        for(int i = frame_num * 10; i < (frame_num * 10) + 10 ; i++)
        {
            if((i / 10) == 0 /*|| (i / 10) == 1 || (i / 10) == 2 || (i / 10) == 3 || (i / 10) == 4 || (i / 10) == 5 || (i / 10) == 6 || (i / 10) == 7 || (i / 10) == 8 || (i / 10) == 9 \
               || (i / 10) == 10 || (i / 10) == 11 || (i / 10) == 12 || (i / 10) == 13 || (i / 10) == 14 || (i / 10) == 15 || (i / 10) == 16 || (i / 10) == 17 || (i / 10) == 18 \
               || (i / 10) == 19 || (i / 10) == 20 || (i / 10) == 21 || (i / 10) == 22 || (i / 10) == 23 || (i / 10) == 24 || (i / 10) == 25 || (i / 10) == 26 || (i / 10) == 27*/)
            {
                recieved.push_back('-');
            }
            else
                recieved.insert(recieved.begin() + i, stored[i]);
        }
        data_arrival_notification = true;
        int iterator = Sn / 8;
        cout << "Frame " << Sn - (8 * iterator) << " Sent\n";
    }
    void send_frame2(int frame_num)
    {
        cout << "Sending Frame To Receiver 2\n";
        for(int i = frame_num * 10; i < (frame_num * 10) + 10; i++)
        {
            if((i / 10) == 0 /*|| (i / 10) == 1 || (i / 10) == 2 || (i / 10) == 3 || (i / 10) == 4 || (i / 10) == 5 || (i / 10) == 6 || (i / 10) == 7 || (i / 10) == 8 || (i / 10) == 9 \
               || (i / 10) == 10 || (i / 10) == 11 || (i / 10) == 12 || (i / 10) == 13 || (i / 10) == 14 || (i / 10) == 15 || (i / 10) == 16 || (i / 10) == 17 || (i / 10) == 18 \
               || (i / 10) == 19 || (i / 10) == 20 || (i / 10) == 21 || (i / 10) == 22 || (i / 10) == 23 || (i / 10) == 24 || (i / 10) == 25 || (i / 10) == 26 || (i / 10) == 27*/)
            {
                recieved2.push_back('-');
            }
            else
                recieved2.insert(recieved2.begin() + i, stored[i]);
        }
        data_arrival_notification2 = true;
        int iterator = Sn2 / 8;
        cout << "Frame " << Sn2 - (8 * iterator) << " Sent\n";
    }
    void send_frame_again(int frame_num)
    {
        cout << "Sending Frame To Receiver 1\n";
        int j = frame_num * 10;
        for(int i = 10 * frame_num; i < (10 * frame_num) + 10 ; i++)
        {
            recieved[i] = stored[i];
            j++;
        }
        data_arrival_notification = true;
        int iterator = frame_num / 8;
        cout << "Frame " << frame_num - (8 * iterator) << " Sent Again\n";
    }
    void send_frame_again2(int frame_num)
    {
        cout << "Sending Frame To Receiver 2\n";
        int j = frame_num * 10;
        for(int i = 10 * frame_num; i < (10 * frame_num) + 10 ; i++)
        {
            recieved2[i] = stored[i];
            j++;
        }
        data_arrival_notification2 = true;
        int iterator = frame_num / 8;
        cout << "Frame " << frame_num - (8 * iterator) << " Sent Again\n";
    }
    void recieve_ack(int ack_num)
    {
        cout << "\nRecieved acknowledge from the Reciever 1 Site\n";
        int iterator = ack_num / 8;
        cout << "ack number: " << ack_num - (8 * iterator) << "\n";
    }
    void recieve_ack2(int ack_num)
    {
        cout << "\nRecieved acknowledge from the Reciever 2 Site\n";
        int iterator = ack_num / 8;
        cout << "ack number: " << ack_num - (8 * iterator) << "\n";
    }

    void deliver_data(int frame_num)
    {
        cout << "\n(Reciever 1 Site)\n";
        cout << "We have recieved the following data: ";

        for(int i = frame_num * 10; i < (frame_num * 10) + 10; i++)
        {
            final_message.push_back(recieved[i]);
            if(recieved[i] == '*')
                break;
        }
        for(int i = 0; i < final_message.size(); i++)
            cout << final_message[i];
        cout << endl;
    }
    void deliver_data2(int frame_num)
    {
        cout << "\n(Reciever 2 Site)\n";
        cout << "We have recieved the following data: ";

        for(int i = frame_num * 10; i < (frame_num * 10) + 10; i++)
        {
            final_message2.push_back(recieved2[i]);
            if(recieved2[i] == '*')
                break;
        }
        for(int i = 0; i < final_message2.size(); i++)
            cout << final_message2[i];
        cout << endl;
    }
    void correct_data(int frame_num)
    {
        cout << "\n(Reciever 1 Site)\n";
        cout << "We have recieved the following data: ";

        int j = frame_num * 10;
        for(int i = frame_num * 10; i < (frame_num * 10) + 10; i++)
        {
            final_message[j] = recieved[i];
            j++;
            if(recieved[i] == '*')
                break;
        }
    }
    void correct_data2(int frame_num)
    {
        cout << "\n(Reciever 2 Site)\n";
        cout << "We have recieved the following data: ";

        int j = frame_num * 10;
        for(int i = frame_num * 10; i < (frame_num * 10) + 10; i++)
        {
            final_message2[j] = recieved2[i];
            j++;
            if(recieved2[i] == '*')
                break;
        }
    }
    void send_ack(int ack_num)
    {
        cout << "\nSending acknowledge from Receiver 1 to the Sender Site";
        int iterator = ack_num / 8;
        cout << "\nack number: " << ack_num - (8 * iterator) << "\n\n";
        ack_number = ack_num;
        ack_arrival_notification = true;
    }
    void send_ack2(int ack_num)
    {
        cout << "\nSending acknowledge from Receiver 2 to the Sender Site";
        int iterator = ack_num / 8;
        cout << "\nack number: " << ack_num - (8 * iterator) << "\n\n";
        ack_number2 = ack_num;
        ack_arrival_notification2 = true;
    }
    bool corrupted_frame(vector<char>frame)
    {
        for(int i = 0; i < frame.size(); i++)
        {
            if(frame[i] == '-') //if any of the recieved elements is '-' -> assume corrupted
                return true; //corrupted frame (packet loss)
        }
        return false;
    }
    bool corrupted_frame_for_checking_each_frame(vector<char>frame, int frame_num)
    {
        for(int i = frame_num * 10; i < (frame_num * 10) + 10; i++)
        {
            if(frame[i] == '-' && frame[i + 1] == '-' && frame[i + 2] == '-' && frame[i + 3] == '-' && frame[i + 4] == '-')
                return true; //corrupted frame (packet loss)
        }
        return false;
    }
};

int main(void)
{
    int chosen_protocol;
    cout << "Network 1 Project\n\n";
    cout << "\t1.Stop & Wait\n\t2.Go Back N\n\t3.Selective Repeat\n\n";
    cout << "Which Protocol You Want To Use (1/2/3)? ";
    cin >> chosen_protocol;
    while(chosen_protocol != 1 && chosen_protocol != 2 && chosen_protocol != 3)
    {
        cout << "\nWrong Choice! Which Protocol You Want To Use? (1/2/3) ";
        cin >> chosen_protocol;
    }
    switch (chosen_protocol)
    {
        case 1: //stop and wait
        {
            system("CLS");
            stop_and_wait object;

            srand(time(0));
            int rand_num_ack = rand() % (2 - 1 + 1) + 1;
            cout << "Random Ack Loss Will Happen at Ack Number: " << rand_num_ack << endl << endl;

            object.get_data();

            auto start = high_resolution_clock::now();
            for(int i = 0; i < 1000; i++) //we can iterate as much as we want
            {
                if(object.check_for_break() == true)
                    break;

                while(true)
                {
                    if(object.request_to_send == true && object.can_send == true)
                    {
                        object.send_frame(object.Sn);
                        object.ack_arrival_notification = false;
                        object.can_send = false;
                        object.time_out = false;
                        object.Sn++;
                    }
                    if(object.request_to_send2 == true && object.can_send2 == true)
                    {
                        object.send_frame2(object.Sn2);
                        object.ack_arrival_notification2 = false;
                        object.can_send2 = false;
                        object.time_out2 = false;
                        object.Sn2++;
                    }
                    if(object.ack_arrival_notification == true)
                    {
                        object.recieve_ack(object.ack_number);
                        if(object.ack_number == rand_num_ack)
                        {
                            cout << "\nAck Loss from Reciever 1\n";
                            object.time_out = true;
                            rand_num_ack = 9999;
                        }
                        else
                        {
                            if(object.ack_number == object.Sn)
                            {
                                cout << "\nRecieved acknowledge from the Reciever 1 Site\n";
                                if(object.ack_number % 2 == 0)
                                    cout << "ack number: " << 0 << "\n\n";
                                else
                                    cout << "ack number: " << 1 << "\n\n";
                                object.can_send = true;
                                object.data_arrival_notification = false;
                                object.time_out = false;
                            }
                        }
                    }
                    if(object.ack_arrival_notification2 == true)
                    {
                        object.recieve_ack2(object.ack_number2);
                        if(object.ack_number2 == rand_num_ack)
                        {
                            cout << "\nAck Loss from Receiver 2\n";
                            object.time_out2 = true;
                            rand_num_ack = 9999;
                        }
                        else
                        {
                            if(object.ack_number2 == object.Sn2)
                            {
                                cout << "\nRecieved acknowledge from the Reciever 2 Site\n";
                                if(object.ack_number2 % 2 == 0)
                                    cout << "ack number: " << 0 << "\n\n";
                                else
                                    cout << "ack number: " << 1 << "\n\n";
                                object.can_send2 = true;
                                object.data_arrival_notification2 = false;
                                object.time_out2 = false;
                            }
                        }
                    }
                    if(object.time_out == true)
                    {
                        cout << "\nTime Out for Receiver 1\n\n";
                        object.send_frame_again(object.Sn - 1);
                        object.data_arrival_notification = true;
                    }
                    if(object.time_out2 == true)
                    {
                        cout << "\nTime Out for Receiver 2\n\n";
                        object.send_frame_again2(object.Sn2 - 1);
                        object.data_arrival_notification2 = true;
                    }
                    break;
                }
                if(object.check_for_break() == true)
                    break;

                while(true)
                {
                    if(object.data_arrival_notification == true)
                    {
                        if(object.Sn - 1 == object.Rn)
                        {
                            if(object.corrupted_frame(object.recieved) == true)
                            {
                                cout << "\nPacket Loss for Receiver 1\n";
                                if(object.Rn % 2 == 0)
                                    cout << "Frame " << 0 << " received like this : -----\n\n";
                                else
                                    cout << "Frame " << 1 << " received like this : -----\n\n";
                                object.time_out = true;
                            }
                            else
                            {
                                object.deliver_data(object.Sn - 1);
                                object.Rn++;
                            }
                        }
                        if(object.check_for_break1() == false)
                        {
                            object.send_ack(object.Rn);
                        }
                        if(object.check_for_break1() == true)
                        {
                            object.request_to_send = false;
                            object.can_send = false;
                            object.time_out = false;
                            object.ack_arrival_notification = false;
                            object.data_arrival_notification = false;
                        }
                    }
                    if(object.data_arrival_notification2 == true)
                    {
                        if(object.Sn2 - 1 == object.Rn2)
                        {
                            if(object.corrupted_frame(object.recieved2) == true)
                            {
                                cout << "\nPacket Loss for Receiver 2\n";
                                if(object.Rn2 % 2 == 0)
                                    cout << "Frame " << 0 << " received like this : -----\n\n";
                                else
                                    cout << "Frame " << 1 << " received like this : -----\n\n";
                                object.time_out2 = true;
                                break;
                            }
                            else
                            {
                                object.deliver_data2(object.Sn2 - 1);
                                object.Rn2++;
                            }
                        }
                        if(object.check_for_break2() == false)
                        {
                            object.send_ack2(object.Rn2);
                        }
                        if(object.check_for_break2() == true)
                        {
                            object.request_to_send2 = false;
                            object.can_send2 = false;
                            object.time_out2 = false;
                            object.ack_arrival_notification2 = false;
                            object.data_arrival_notification2 = false;
                        }
                    }
                    break;
                }
            }
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start);
            cout << "\nTime taken by Stop & Wait: " <<  duration.count() << " milliseconds" << endl;
            break;
        }
        case 2: //go back n
        {
            system("CLS");
            go_back_n object;

            object.get_data();

            auto start = high_resolution_clock::now();
            for(int i = 0; i < 1000; i++) //we can iterate as much as we want
            {
                if(object.check_for_break() == true)
                    break;

                while(true)
                {
                    if(object.request_to_send == true)
                    {

                        if(object.Sn - object.Sf >= object.Sw - object.Sf)
                        {
                            object.time_out = true;
                            object.request_to_send = false;
                        }
                        else
                        {
                            object.send_frame(object.Sn);
                            object.Sn++;
                        }
                    }
                    if(object.request_to_send2 == true)
                    {

                        if(object.Sn2 - object.Sf2 >= object.Sw2 - object.Sf2)
                        {
                            object.time_out2 = true;
                            object.request_to_send2 = false;
                        }
                        else
                        {
                            object.send_frame2(object.Sn2);
                            object.Sn2++;
                        }
                    }
                    if(object.ack_arrival_notification == true)
                    {
                        object.recieve_ack(object.ack_number);
                        if(object.Sf < object.ack_number && object.ack_number < object.Sn)
                            while(object.Sf < object.ack_number)
                            {
                                object.Sf++;
                                object.Sw++;
                            }
                    }
                    if(object.ack_arrival_notification2 == true)
                    {
                        object.recieve_ack2(object.ack_number2);
                        if(object.Sf2 < object.ack_number2 && object.ack_number2 < object.Sn2)
                            while(object.Sf2 < object.ack_number2)
                            {
                                object.Sf2++;
                                object.Sw2++;
                            }
                    }
                    if(object.time_out == true)
                    {
                        cout << "Time Out for Receiver 1\n\n";
                        int i = 0;
                        while(i < 4)
                        {
                            object.send_frame_again(object.Rn);
                            object.deliver_data(object.Rn);
                            object.Rn++;
                            if(object.check_for_break1() == false)
                                object.send_ack(object.Rn);
                            if(object.check_for_break1() == true)
                            {
                                object.request_to_send = false;
                                object.time_out = false;
                                object.ack_arrival_notification = false;
                                object.data_arrival_notification = false;
                            }
                            i++;
                        }
                        object.Sf += 4;
                        object.Sw += 4;
                        object.data_arrival_notification = false;
                        object.request_to_send = true;
                        object.time_out = false;
                        Sleep(10);
                    }
                    if(object.time_out2 == true)
                    {
                        cout << "Time Out for Receiver 2\n\n";
                        int i = 0;
                        while(i < 4)
                        {
                            object.send_frame_again2(object.Rn2);
                            object.deliver_data2(object.Rn2);
                            object.Rn2++;
                            if(object.check_for_break2() == false)
                                object.send_ack2(object.Rn2);
                            if(object.check_for_break2() == true)
                            {
                                object.request_to_send2 = false;
                                object.time_out2 = false;
                                object.ack_arrival_notification2 = false;
                                object.data_arrival_notification2 = false;
                            }
                            i++;
                        }
                        object.Sf2 += 4;
                        object.Sw2 += 4;
                        object.data_arrival_notification2 = false;
                        object.request_to_send2 = true;
                        object.time_out2 = false;
                        Sleep(10);
                    }
                    break;
                }
                if(object.check_for_break() == true)
                    break;

                while(true)
                {
                    if(object.data_arrival_notification == true)
                        if(object.Sn - 1 == object.Rn)
                        {
                            if(object.corrupted_frame(object.recieved) == true)
                                cout << "\nWarning from Receiver 1! There is a Packet Loss\n\n";
                            else
                            {
                                object.Rn++;
                                object.deliver_data(object.Sn - 1);
                                if(object.check_for_break1() == false)
                                    object.send_ack(object.Rn);
                                if(object.check_for_break1() == true)
                                {
                                    object.request_to_send = false;
                                    object.time_out = false;
                                    object.ack_arrival_notification = false;
                                    object.data_arrival_notification = false;
                                }
                            }
                        }
                    if(object.data_arrival_notification2 == true)
                        if(object.Sn2 - 1 == object.Rn2)
                        {
                            if(object.corrupted_frame(object.recieved2) == true)
                                cout << "\nWarning from Receiver 2! There is a Packet Loss\n\n";
                            else
                            {
                                object.Rn2++;
                                object.deliver_data2(object.Sn2 - 1);
                                if(object.check_for_break2() == false)
                                    object.send_ack2(object.Rn2);
                                if(object.check_for_break2() == true)
                                {
                                    object.request_to_send2 = false;
                                    object.time_out2 = false;
                                    object.ack_arrival_notification2 = false;
                                    object.data_arrival_notification2 = false;
                                }
                            }
                        }
                    break;
                }
            }
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start);
            cout << "\nTime taken by Go Back N: " <<  duration.count() << " milliseconds" << endl;
            break;
        }
        case 3: //selective repeat
        {
            system("CLS");
            selective_repeat object; object.build_vector();

            object.get_data();

            auto start = high_resolution_clock::now();
            for(int i = 0; i < 1000; i++) //we can iterate as much as we want
            {
                if(object.check_for_break() == true)
                    break;

                while(true)
                {
                    if(object.request_to_send == true)
                    {
                        if(object.Sn - object.Sf >= object.Sw - object.Sf)
                        {
                            object.time_out = true;
                            object.request_to_send = false;
                        }
                        else
                        {
                            object.send_frame(object.Sn);
                            object.Sn++;
                        }
                    }
                    if(object.request_to_send2 == true)
                    {
                        if(object.Sn2 - object.Sf2 >= object.Sw2 - object.Sf2)
                        {
                            object.time_out2 = true;
                            object.request_to_send2 = false;
                        }
                        else
                        {
                            object.send_frame2(object.Sn2);
                            object.Sn2++;
                        }
                    }
                    if(object.ack_arrival_notification == true)
                    {
                        object.recieve_ack(object.ack_number);
                        if(object.Sf < object.ack_number && object.ack_number < object.Sn)
                            while(object.Sf < object.ack_number)
                            {
                                object.Sf++;
                                object.Sw++;
                            }
                    }
                    if(object.ack_arrival_notification2 == true)
                    {
                        object.recieve_ack2(object.ack_number2);
                        if(object.Sf2 < object.ack_number2 && object.ack_number2 < object.Sn2)
                            while(object.Sf2 < object.ack_number2)
                            {
                                object.Sf2++;
                                object.Sw2++;
                            }
                    }
                    if(object.time_out == true)
                    {
                        cout << "Time Out for Receiver 1\n\n";
                        if(object.time_out_0 == true)
                        {
                            cout << "Time Out For Frame 0 in Window\n" << endl;
                            object.send_frame_again(object.Sn - 4);
                            object.correct_data(object.Sn - 4);
                        }
                        if(object.time_out_1 == true)
                        {
                            cout << "Time Out For Frame 1 in Window\n" << endl;
                            object.send_frame_again(object.Sn - 3);
                            object.correct_data(object.Sn - 3);
                        }
                        if(object.time_out_2 == true)
                        {
                            cout << "Time Out For Frame 2 in Window\n" << endl;
                            object.send_frame_again(object.Sn - 2);
                            object.correct_data(object.Sn - 2);
                        }
                        if(object.time_out_3 == true)
                        {
                            cout << "Time Out For Frame 3 in Window\n" << endl;
                            object.send_frame_again(object.Sn - 1);
                            object.correct_data(object.Sn - 1);
                        }
                        object.Rn += 4;
                        object.Sf += 4;
                        object.Sw += 4;
                        object.send_ack(object.Rn);
                        object.ack_needed = false;

                        object.request_to_send = true;

                        object.time_out = false;
                        object.time_out_0 = false;
                        object.time_out_1 = false;
                        object.time_out_2 = false;
                        object.time_out_3 = false;
                    }
                    if(object.time_out2 == true)
                    {
                        cout << "Time Out for Receiver 2\n\n";
                        if(object.time_out_02 == true)
                        {
                            cout << "Time Out For Frame 0 in Window\n" << endl;
                            object.send_frame_again2(object.Sn2 - 4);
                            object.correct_data2(object.Sn2 - 4);
                        }
                        if(object.time_out_12 == true)
                        {
                            cout << "Time Out For Frame 1 in Window\n" << endl;
                            object.send_frame_again2(object.Sn2 - 3);
                            object.correct_data2(object.Sn2 - 3);
                        }
                        if(object.time_out_22 == true)
                        {
                            cout << "Time Out For Frame 2 in Window\n" << endl;
                            object.send_frame_again2(object.Sn2 - 2);
                            object.correct_data2(object.Sn2 - 2);
                        }
                        if(object.time_out_32 == true)
                        {
                            cout << "Time Out For Frame 3 in Window\n" << endl;
                            object.send_frame_again2(object.Sn2 - 1);
                            object.correct_data2(object.Sn2 - 1);
                        }
                        object.Rn2 += 4;
                        object.Sf2 += 4;
                        object.Sw2 += 4;
                        object.send_ack2(object.Rn2);
                        object.ack_needed2 = false;

                        object.request_to_send2 = true;

                        object.time_out2 = false;
                        object.time_out_02 = false;
                        object.time_out_12 = false;
                        object.time_out_22 = false;
                        object.time_out_32 = false;
                    }
                    break;
                }
                if(object.check_for_break() == true)
                    break;

                while(true)
                {
                    if(object.data_arrival_notification == true)
                    {
                        if(object.Sn != object.Rn)
                        {
                            if(object.corrupted_frame(object.recieved) == true)
                            {
                                cout << "\nWarning from Receiver 1! There is a Packet Loss\n";
                                object.deliver_data(object.Sn - 1);

                                int num_of_frame_in_window = (object.Sn - 1) - object.Sf;

                                if(num_of_frame_in_window == 0 && object.corrupted_frame_for_checking_each_frame(object.recieved, object.Sn - 1) == true)
                                {
                                    cout << "\nPacket Loss at Window Frame Number 0 Recognized" << endl;
                                    object.time_out_0 = true;
                                }
                                if(num_of_frame_in_window == 1 && object.corrupted_frame_for_checking_each_frame(object.recieved, object.Sn - 1) == true)
                                {
                                    cout << "\nPacket Loss at Window Frame Number 1 Recognized" << endl;
                                    object.time_out_1 = true;
                                }
                                if(num_of_frame_in_window == 2 && object.corrupted_frame_for_checking_each_frame(object.recieved, object.Sn - 1) == true)
                                {
                                    cout << "\nPacket Loss at Window Frame Number 2 Recognized" << endl;
                                    object.time_out_2 = true;
                                }
                                if(num_of_frame_in_window == 3 && object.corrupted_frame_for_checking_each_frame(object.recieved, object.Sn - 1) == true)
                                {
                                    cout << "\nPacket Loss at Window Frame Number 3 Recognized" << endl;
                                    object.time_out_3 = true;
                                }
                                cout << endl;
                            }
                            else
                            {
                                if((object.Sf < object.Sn  && object.Sn < object.Sw) && object.marked[object.Sn] == false)
                                {
                                    object.marked[object.Sn - 1] = true;
                                    object.deliver_data(object.Sn - 1);
                                    object.Rn++;
                                    object.ack_needed = true;
                                }
                                if(object.ack_needed == true)
                                {
                                    if(object.check_for_break1() == false)
                                    {
                                        object.send_ack(object.Rn);
                                        object.ack_needed = false;
                                    }
                                    if(object.check_for_break1() == true)
                                    {
                                        object.request_to_send = false;
                                        object.ack_needed = false;
                                        object.ack_arrival_notification = false;
                                        object.data_arrival_notification = false;
                                        object.time_out = false;
                                        object.time_out_0 = false;
                                        object.time_out_1 = false;
                                        object.time_out_2 = false;
                                        object.time_out_3 = false;
                                    }
                                }
                            }
                        }
                    }
                    if(object.data_arrival_notification2 == true)
                    {
                        if(object.Sn2 != object.Rn2)
                        {
                            if(object.corrupted_frame(object.recieved2) == true)
                            {
                                cout << "\nWarning from Receiver 2! There is a Packet Loss\n";
                                object.deliver_data2(object.Sn2 - 1);

                                int num_of_frame_in_window = (object.Sn2 - 1) - object.Sf2;

                                if(num_of_frame_in_window == 0 && object.corrupted_frame_for_checking_each_frame(object.recieved2, object.Sn2 - 1) == true)
                                {
                                    cout << "\nPacket Loss at Window Frame Number 0 Recognized" << endl;
                                    object.time_out_02 = true;
                                }
                                if(num_of_frame_in_window == 1 && object.corrupted_frame_for_checking_each_frame(object.recieved2, object.Sn2 - 1) == true)
                                {
                                    cout << "\nPacket Loss at Window Frame Number 1 Recognized" << endl;
                                    object.time_out_12 = true;
                                }
                                if(num_of_frame_in_window == 2 && object.corrupted_frame_for_checking_each_frame(object.recieved2, object.Sn2 - 1) == true)
                                {
                                    cout << "\nPacket Loss at Window Frame Number 2 Recognized" << endl;
                                    object.time_out_22 = true;
                                }
                                if(num_of_frame_in_window == 3 && object.corrupted_frame_for_checking_each_frame(object.recieved2, object.Sn2 - 1) == true)
                                {
                                    cout << "\nPacket Loss at Window Frame Number 3 Recognized" << endl;
                                    object.time_out_32 = true;
                                }
                                cout << endl;
                            }
                            else
                            {
                                if((object.Sf2 < object.Sn2  && object.Sn2 < object.Sw2) && object.marked2[object.Sn2] == false)
                                {
                                    object.marked2[object.Sn2 - 1] = true;
                                    object.deliver_data2(object.Sn2 - 1);
                                    object.Rn2++;
                                    object.ack_needed2 = true;
                                }
                                if(object.ack_needed2 == true)
                                {
                                    if(object.check_for_break2() == false)
                                    {
                                        object.send_ack2(object.Rn2);
                                        object.ack_needed2 = false;
                                    }
                                    if(object.check_for_break2() == true)
                                    {
                                        object.request_to_send2 = false;
                                        object.ack_needed2 = false;
                                        object.ack_arrival_notification2 = false;
                                        object.data_arrival_notification2 = false;
                                        object.time_out2 = false;
                                        object.time_out_02 = false;
                                        object.time_out_12 = false;
                                        object.time_out_22 = false;
                                        object.time_out_32 = false;
                                    }
                                }
                            }
                        }
                    }
                    break;
                }
            }
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start);
            cout << "\nTime taken by Selective Repeat: " <<  duration.count() << " milliseconds" << endl;
            break;
        }
        default:
            exit(EXIT_FAILURE);
    }
    cout << endl << endl;
    return 0;
}
