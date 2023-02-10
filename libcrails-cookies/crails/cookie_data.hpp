#ifndef  COOKIE_DATA_HPP
# define COOKIE_DATA_HPP

# include <string>
# include <crails/datatree.hpp>

namespace Crails
{
  struct CookieData : public DataTree
  {
    CookieData(const std::string& password, const std::string& salt);
    CookieData();

    void        unserialize(const std::string&);
    std::string serialize(void);

    const std::string& password;
    const std::string& salt;
    const bool         use_encryption = false;
  };
}

#endif
