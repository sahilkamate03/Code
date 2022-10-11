import React from 'react'
import {TodoItem} from './todo'

export default function todos(props) {
    return (
        <div className='container'>
            <h3 className='text-center'>Todos List</h3>
            {props.todos[1]}
        </div>
    )
}
