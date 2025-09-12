#ifndef CONFIG
#define CONFIG

#include "src/json.hpp"

class Config {
public:
    static Config& GetInstance() {
        static Config instance;
        return instance;
    }

    template<typename T>
    T Get(const std::string& key) const {
        return data[key].get<T>();
    }

    template<typename T>
    void Set(const std::string& key, const T& value) {
        data[key] = value;
    }

    void SaveToFile();
    void LoadFromFile();

private:
    nlohmann::json data;
    Config();

    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;
};

#endif // CONFIG