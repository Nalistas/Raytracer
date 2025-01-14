/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** DLLoader
*/

#include "Core/DLLoader.hpp"

template class DLLdr::DLLoader<void (*)()>;

DLLdr::DLLoaderException::DLLoaderException(DLLdr::DLLoaderExcepId id) :
m_id(id)
{}

const char *DLLdr::DLLoaderException::what(void) const noexcept
{
    if (m_id == LibNotOpened)
        return "lib not opened";

    if (m_id == SymNotFound)
        return "symbol not found";

    if (m_id == SymTypeMismatch)
        return "symbol type mismatch";
    return "unknown error";
}

template<typename T>
DLLdr::DLLoader<T>::DLLoader() : m_lib(nullptr)
{}

template<typename T>
DLLdr::DLLoader<T>::~DLLoader()
{
    close();
}

template<typename T>
void DLLdr::DLLoader<T>::close(void)
{
    if (m_lib != nullptr) {
        dlclose(m_lib);
        m_lib = nullptr;
    }
}

template<typename T>
void DLLdr::DLLoader<T>::open(const std::string &filename)
{
    close();
    m_lib = dlopen(filename.c_str(), RTLD_LAZY);
    if (m_lib == NULL) {
        std::cerr << dlerror() << std::endl;
        throw DLLdr::DLLoaderException(DLLdr::LibNotOpened);
    }
}

template<typename T>
std::unique_ptr<T> DLLdr::DLLoader<T>::getSym()
{
    void *sym = dlsym(m_lib, "entryPoint");

    if (sym == nullptr) {
        throw DLLdr::DLLoaderException(DLLdr::SymNotFound);
    }

    std::function<std::unique_ptr<T>()> entryPoint = reinterpret_cast<std::unique_ptr<T>(*)()>(sym);
    std::unique_ptr<T> ptr = entryPoint();
    return ptr;
}
