#include <string>
#include <vector>

// Behaviors
class Specifier;
class Optional;

// Options
class Flag;
class Option;
class Argument;

// A standard command line interface is a vector of specifiers
typedef std::vector<Specifier> stdcli;

class Specifier {
  private:
    std::string shortflag;
    std::string longflag;
    std::string metavar;
    std::string help;
  public:
    Specifier(std::string shortflag = "", std::string longflag = "", std::string metavar = "[argument]", std::string help = "");

    // Getters
    std::string getShort()      { return this->shortflag; }
    std::string getLong()       { return this->longflag; }
    std::string getMetavar()    { return this->metavar; }
    std::string getHelp()       { return this->help; }

    // Setters
    void setHelp(std::string help)      { this->help = help; }
    void setShort(std::string shortflag) { this->shortflag = shortflag; }
    void setLong(std::string longflag)   { this->longflag = longflag; }
    void setMetavar(std::string metavar) { this->metavar = metavar; }
};

class Optional {
  private:
    bool toggled;
  public:
};

class Argument : public Specifier {
  private:
      typedef Specifier super;

  public:
    Argument(std::string shortflag , std::string longflag,
            std::string metavar, std::string help) {
        super(shortflag, longflag, metavar, help);
    }
};

class Flag : public Specifier, public Optional {
  private:
      typedef Specifier super;
  public:
    Flag(std::string shortflag , std::string longflag,
            std::string metavar, std::string help) {
        super(shortflag, longflag, metavar, help);
    }
};

class Option : public Specifier, public Optional {
  private:
      typedef Specifier super;
  public:
    Option(std::string shortflag , std::string longflag,
            std::string metavar, std::string help) {
        super(shortflag, longflag, metavar, help);
    }
};

// Example cli
stdcli cli = {
    Argument("-h", "--help", "", "Show this help message"),
    Option("-v", "--verbose", "", "Show verbose output")
};

//struct Args {
    //std::vector<Argument> args;
//};

//Args cli = std::make_tuple {
    //Argument {};
//};

//Argument();
