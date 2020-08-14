#include <gtest/gtest.h>
#include <ctime>
#include "model.h"
#include <iostream>
#include <unordered_map>
#include <iomanip> 

struct TestUsers : public testing::Test
/*
Test Setup Struct for User and UserModel.
This will allow us to use Google Test Fixture to conduct Test on the User object and UserModel
*/
{
    User *user1, *user2, *user3, *user4;
    UserModel *u;
    void SetUp()
    {
        time_t t = time(NULL);

        user1 = new User("Michael", "Okolo", "mokolo", "mokolo@example.com", "p12345", "0123456789", "Ultimo Torrens University", t);
        user2 = new User("Vinicius", "Borghetti", "vborghetti", "viniciusborghetti@gmail.com", "jfaldsjfw9eHFSOH0843", "3924823349", "Bondi Junction", t);
        user3 = new User("Diego", "Rojas", "drojas", "drojas@gmail.com", "jfaldsjfw9eHFSOH0843", "3924823349", "Torres Parramatta Junction", t);
        user4 = new User("Fernando", "Dayan", "fdayan", "fdayan@gmail.com", "jfaldsjfw9eHFSOH0843", "3924823349", "Llandilo Penrith NSW", t);
        
        user1 -> user_id = 1;
        user2 -> user_id = 2;
        user3 -> user_id = 4;
        user4 -> user_id = 3;
        
        u = new UserModel();
        u -> filename = "test_users.csv";
    }

    void TearDown()
    {
        delete user1, user2;
        delete u;
    }
};

TEST_F(TestUsers, TestSaveUser)
{
    ASSERT_TRUE(u -> save(*user1));
    ASSERT_TRUE(u -> save(*user2));
}

TEST_F(TestUsers, TestLoadAllUser)
{
    ASSERT_GE(u->all().size(), 2);
}

TEST_F(TestUsers, UpdateUsersRecord)
{
    ASSERT_TRUE(u -> update());
}

TEST_F(TestUsers, TestSaveAllUsers)
{
    std::vector<User> m_users = {*user1, *user2, *user3, *user4};
    ASSERT_TRUE(u -> save_all(m_users));
    ASSERT_GE(u -> all().size(), 2);
}

TEST_F(TestUsers, TestgetLastId)
{
    EXPECT_EQ(u->getLastId(), 4);
}

TEST_F(TestUsers, TestUserInfo)
{
    unordered_map<string, string> user_map = user1 -> getUserInfo(1);
    unordered_map<string, string> user_map2 = user2 -> getUserInfo(2);

    EXPECT_STREQ(user_map["username"].c_str(), user1 -> username.c_str());
    EXPECT_STREQ(user_map2["username"].c_str(), user2 -> username.c_str());
    EXPECT_STREQ(user_map["user_id"].c_str(), "1");
    EXPECT_STREQ(user_map2["user_id"].c_str(), "2");
}