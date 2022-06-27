#pragma once

namespace heartbeat {
class Heart {
public:
    
    explicit Heart(unsigned long timeout = 100);

    /**
     * @brief reset the heartbeat timeout
     * 
     */
    void ResetHeart();

    /**
     * @brief timeout exceeded y/n
     * 
     */
    bool HeartDead();

private:
    unsigned long m_timeout;
    unsigned long m_lastBeat;

};
} // namespace heart