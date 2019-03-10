#include <gtest/gtest.h>
#include <exceptions/BadFileFormat.hpp>
#include "filesystem/ZipFilesystem.hpp"
#include "exceptions/NoSuchFile.hpp"

TEST(ZipFilesystem, openValidFile) {
    gplib::filesystem::ZipFilesystem fs;

    ASSERT_FALSE(fs.isOpen());
    ASSERT_NO_THROW(fs.open("assets/testfile.zip"));
    ASSERT_TRUE(fs.isOpen());
}

TEST(ZipFilesystem, openUnexistingFile) {
    gplib::filesystem::ZipFilesystem fs;

    ASSERT_FALSE(fs.isOpen());
    ASSERT_THROW(fs.open("assets/nonExistingFile.zip"), gplib::exceptions::NoSuchFile);
}

TEST(ZipFilesystem, openNonZipFile) {
    gplib::filesystem::ZipFilesystem fs;

    ASSERT_FALSE(fs.isOpen());
    ASSERT_THROW(fs.open("assets/testfile.txt"), gplib::exceptions::BadFileFormat);
}