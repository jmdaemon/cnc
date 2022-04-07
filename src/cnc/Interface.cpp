#include <string>
#include <vector>
#include <functional>

// Behaviors
class Specifier;
class Optional;

// Options
class Flag;
class Option;
class Argument;

// A standard command line interface is a vector of specifiers
typedef std::vector<Specifier> stdcli;

/**
  * A Specifier is an argument that may have a short, or long flag to be passed into the command line.
  */
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

/**
  * An Optional is a behavior of a specifier or flag
  */
class Optional {
  private:
    bool toggled;
  public:
    Optional(bool toggle = false) : toggled(toggle) {}
    void toggle() { this->toggled = true; }
    bool isToggled() { return this->toggled; }
};

/**
  * A command specifies a callback function to be executed when the
  * command's flags are parsed.
  */
class Command : public Specifier {
  private:
      typedef Specifier super;
    
  public:
      //template<typename F> void f(F &lambda) { [> ... <]}
    template<typename F>
    Command(std::string shortflag = "", std::string longflag = "",
            std::string metavar = "command", std::string help = "",
            F &cb = nullptr) {
      super(shortflag, longflag, metavar, help);
      callback = cb;
    }

    //template<typename F> Command(F &cb) {
      //callback = cb;
    //}

    //template<typename F> void callback(F);
    std::function<void()> callback;

};

/**
  * An argument is a non-optional specifier that
  * must be passed in, else the program will error out.
  */
class Argument : public Specifier {
  private:
      typedef Specifier super;

  public:
    Argument(std::string shortflag , std::string longflag,
            std::string metavar, std::string help) {
        super(shortflag, longflag, metavar, help);
    }
};

/**
  * A flag is an argument that may be turned on or off.
  * It does not accept any arguments.
  */
class Flag : public Specifier, public Optional {
  private:
      typedef Specifier super;
  public:
    Flag(std::string shortflag , std::string longflag,
            std::string metavar, std::string help) {
        super(shortflag, longflag, metavar, help);
    }
};

/**
  * An option is an argument that may have a value passed to it
  * it is not required, but it can change an effect in an application.
  */
class Option : public Specifier, public Optional {
  private:
      typedef Specifier super;
  public:
    Option(std::string shortflag , std::string longflag,
            std::string metavar, std::string help) {
        super(shortflag, longflag, metavar, help);
    }
};

/**
  * A subcommand is a separate subcommand containing its own
  * arguments, options, flags, and help message
  */
class SubCommand {
  private:
    std::string name;
    stdcli cli;
  public:
    SubCommand(std::string = "", stdcli cli = std::vector<Specifier>());
    stdcli getCli();
};

// Example cli

// Initialization
stdcli cli = {
    Argument("-h", "--help", "", "Show this help message"),
    Option("-v", "--verbose", "", "Show verbose output"),
};

// Parsing

// Order of evaluation

// TODO:
// Hook up callbacks
// Allow for multiple passing of arguments after the initial argument
// Allow for subcommands
// Allow for easy iteration in a switch statement
// Allow for default arguments

// Set up CLI in phases
// Phases:
// 1. Declaration
// 2. Defaulting
// 3. Parsing
// 4. Evaluation
// 5. Matching/checking

// Parsing: Let the user add in custom parsing rules
// Matching/checking:
// - Let the user add custom matching rules for arguments
// - Allow for enum switch statement match statements

// Iteration over the arguments
