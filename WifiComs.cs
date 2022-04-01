using UnityEngine;
using System.Net.Sockets;
using System.Text;
using System.Net;
using System;

public class WifiComs : MonoBehaviour
{
    private void Update()
    {
        udpSend();
    }

    //Port and IP Data for Socket Client
    void udpSend()
    {
        var IP = IPAddress.Parse("192.175.0.20"); 

        int port = 4000; 

        var udpClient1 = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
        var sendEndPoint = new IPEndPoint(IP, port);
        var receiveEndPoint = new IPEndPoint(IPAddress.Any, port);

        var clientReturn = new UdpClient(4000);

        try
        {
            //Sends a message to the host to which you have connected.
            byte[] sendBytes = Encoding.ASCII.GetBytes("hello from unity");

            udpClient1.SendTo(sendBytes, sendEndPoint);

            Debug.Log(udpClient1.Available);

            if (udpClient1.Available > 0)
            {
                // Blocks until a message returns on this socket from a remote host.
               byte[] receiveBytes = clientReturn.Receive(ref receiveEndPoint);

                string returnData = Encoding.ASCII.GetString(receiveBytes);

                Debug.Log("Message Received: " +
                                    returnData.ToString());

                if (receiveBytes == null || receiveBytes.Length == 0)
                {
                    Debug.Log("No Answer from Wemos");
                }
            }
            udpClient1.Close();
            clientReturn.Close();
        }
        catch (Exception e)
        {
            Debug.Log(e.ToString());
        }
    }
}