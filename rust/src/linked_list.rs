#[derive(Clone, Debug)]
pub struct LinkedList<T> {
    first: Option<Box<LinkedListEntry<T>>>,
}

#[derive(Clone, Debug)]
pub struct LinkedListEntry<T> {
    next: Option<Box<LinkedListEntry<T>>>,
    item: T,
}

impl<T> LinkedList<T> {
    pub fn new() -> Self {
        Default::default()
    }

    pub fn push(&mut self, item: T) {
        let node = Some(Self::create_next_node(item));
        if let Some(first) = self.first.as_deref_mut() {
            first.last_cell_mut().next = node;
        } else {
            self.first = node;
        }
    }

    pub fn get(&self, idx: usize) -> Option<&T> {
        let Some(first) = &self.first else {
            return None;
        };
        let mut current = first;
        for _ in 0..idx {
            if let Some(next) = current.next.as_ref() {
                current = next;
            } else {
                return None;
            }
        }
        Some(&current.item)
    }

    pub fn empty(&self) -> bool {
        self.first.is_some()
    }

    fn create_next_node(item: T) -> Box<LinkedListEntry<T>> {
        Box::new(LinkedListEntry { item, next: None })
    }
}

impl<T> Default for LinkedList<T> {
    fn default() -> Self {
        Self { first: None }
    }
}

impl<T> LinkedListEntry<T> {
    fn last_cell_mut(&mut self) -> &mut LinkedListEntry<T> {
        if self.next.is_none() {
            return self;
        }
        let mut current = self;
        while let Some(next) = current.next.as_deref_mut() {
            if next.next.is_none() {
                return next;
            }
            current = next;
        }
        unreachable!()
    }
}

#[cfg(test)]
mod test {
    use super::LinkedList;
    #[test]
    fn it_works() {
        let mut list = LinkedList::new();
        list.push(1);
        let output = *list.get(0).unwrap();
        assert_eq!(output, 1)
    }

    #[test]
    fn it_works_bigger() {
        let mut list = LinkedList::new();
        eprintln!("starting");
        for x in 0..=100 {
            list.push(x);
        }
        eprintln!("pushed everything");
        for x in 0..=100 {
            assert_eq!(list.get(x), Some(&x));
        }
    }

    #[test]
    fn really_long_list() {
        let mut list = LinkedList::new();
        eprintln!("starting");
        for x in 0..=100_000 {
            let i = 0;
            list.push(x);
        }
        eprintln!("pushed everything");
        assert_eq!(list.get(100_000), Some(&100_000))
    }
}
