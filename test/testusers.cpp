#include <gtest/gtest.h>
#include "users.h"

struct TestUsers : public testing::Test
{
    User *user1, *user2;
    void SetUp()
    {
        user1 = new User("Michael", "Okolo", "mokolo@outlook.com", "mokolo1", "Infdso8934893biusdf", 29, 1);
        user2 = new User("Vinicius", "Borghetti", "viniciusborghetti@gmail.com", "joates", "jfaldsjfw9eHFSOH0843", 29, 1);
        

    }

    void TearDown()
    {
        delete user1, user2;
    }
};

TEST_F(TestUsers, TestUserRole)
{
    ASSERT_STREQ(user1 -> getRoleDef().c_str(), "ADMINISTRATOR");
}

TEST_F(TestUsers, TestSaveUsers)
{
    ASSERT_TRUE(user1 -> save());
}

TEST_F(TestUsers, TestDeleteUsers)
{
    ASSERT_TRUE(user1 -> deleteUser());
}

TEST_F(TestUsers, TestAllUsers)
{
    user1 -> save();
    user2 -> save();

    ASSERT_GE(um -> allUsers().size(), 2);

    user1 -> deleteUser();
    user2 -> deleteUser();
}

TEST_F(TestUsers, TestSaveAllUsers)
{
    std::vector<Users> m_users = {*user1, *user2};
    ASSERT_TRUE(um -> saveAllUsers(m_users));
    ASSERT_GE(um -> allUsers().size(), 2);

    user1 -> deleteUser();
    user2 -> deleteUser();
}
