/**
    @author Tony Huynh

    @date 2/14/2018
    @version v1.0.0
*/
#ifndef TEAM_HPP
#define TEAM_HPP

class Team {
    private:
        
    public:
        Team();
        void setPointGuard();
        int getPointGuard();
        void setShootingGuard();
        int getPointGuard();
        void setSmallForward();
        int getSmallForward();
        void setPowerForward();
        int getPowerForward();
        void setCenter();
        int getCenter();
        int totalPoints();
};
#endif