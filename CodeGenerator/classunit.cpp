#include "classunit.h"

using std::string;

void ClassUnit::add( const std::shared_ptr< Unit >& unit, Flags flags )
{
    /* в соотсветствующй модификатор доступа(флаг) , то есть в вектор с таким же порядковым
         номером (которые хранятся в m_fields) добавляем новый указатель на unit(то есть
        соотв модификатор добавляем метод( который передаем )*/
    if( flags < ACCESS_MODIFIERS.size() )
    {
        m_fields[ flags ].push_back( unit );
    }
}
string ClassUnit::compile( unsigned int level) const
{
    {
        /* генерируется самая верхняя строка с именем класса и открвающейся скобочкой*/
        std::string result = generateShift( level ) + "class " + m_name + " {\n";

        for( size_t/*для корректного сравнивания
            с рамзером вектора*/ i = 0; i < ACCESS_MODIFIERS.size(); ++i )
        {
            /*если какой то модификатор мы не используем, то не отображаем ничего,
            связанное с ним*/
            if( m_fields[ i ].empty()  )
                continue;

            // для каждого типа модификатора поставим двоеточие
            result += ACCESS_MODIFIERS[ i ] + ":\n";

            /*проходимся по i вектору*/
            for( const auto& f : m_fields[ i ] )
            {
                //вызываем метод compile у класса MethodUnit (для отображения метода в каждом
                // модификаторе
                result += f/*std::shared_ptr<MethodUnit>*/->compile( level + 1 );
                //
            }
            result += "\n";
        }
        result += generateShift( level ) + "};\n";
        return result;
    }
}

// инициализация вектора, которую вынесли
const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public","protected", "private" };


