#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class ISubscriber
{
public:
    virtual void update() = 0;
    ~ISubscriber() {}
};

class IChannel
{
public:
    virtual void subscribe(ISubscriber *subscriber) = 0;
    virtual void unsubscribe(ISubscriber *subscriber) = 0;
    virtual void notifySubscribers() = 0;
    ~IChannel() {}
};

class Channel : public IChannel
{
private:
    std::vector<ISubscriber *> subscribers;
    std::string name;
    std::string latestVideo;

public:
    Channel(const std::string &name)
    {
        this->name = name;
    }

    void subscribe(ISubscriber *subscriber) override
    {
        if (std::find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end())
        {
            subscribers.push_back(subscriber);
        }
    }

    void unsubscribe(ISubscriber *subscriber) override
    {
        auto it = std::find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end())
        {
            subscribers.erase(it);
        }
    }

    void notifySubscribers() override
    {
        for (ISubscriber *sub : subscribers)
        {
            sub->update();
        }
    }

    void uploadVideo(const std::string &title)
    {
        latestVideo = title;
        std::cout << "\n[" << name << " upload \"" << title << "\"]\n";
        notifySubscribers();
    }

    std::string getVideoData()
    {
        return "\ncheck out our new video : " + latestVideo + "\n";
    }
};

class Subscriber : public ISubscriber
{
private:
    std::string name;
    Channel *channel;

public:
    Subscriber(const std::string &name, Channel *channel)
    {
        this->name = name;
        this->channel = channel;
    }

    void update()
    {
        std::cout << "hey " << name << " ," << this->channel->getVideoData();
    }
};

int main()
{
    Channel *channel = new Channel("myTube");
    Subscriber *sub1 = new Subscriber("Aziz", channel);
    Subscriber *sub2 = new Subscriber("Taufique", channel);

    channel->subscribe(sub1);
    channel->subscribe(sub2);

    channel->uploadVideo("illuminati");

    channel->unsubscribe(sub1);

    channel->uploadVideo("char botel vodka");
    return 0;
}