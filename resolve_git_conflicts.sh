#!/bin/bash

echo "🔄 Resolving Git merge conflicts automatically..."

# 解析 `git status` 并逐行处理冲突文件
git status | while IFS= read -r line; do
    case "$line" in
        *"deleted by them:"*)
            file=$(echo "$line" | sed -E 's/.*deleted by them:\s+//')
            echo "🗑 Removing (deleted by them): $file"
            git rm -f "$file"
            ;;
        *"added by us:"*)
            file=$(echo "$line" | sed -E 's/.*added by us:\s+//')
            echo "✅ Adding (added by us): $file"
            git add "$file"
            ;;
        *"both deleted:"*)
            file=$(echo "$line" | sed -E 's/.*both deleted:\s+//')
            echo "🗑 Removing (both deleted): $file"
            git rm -f "$file"
            ;;
        *"added by them:"*)
            file=$(echo "$line" | sed -E 's/.*added by them:\s+//')
            echo "🔄 Checking out theirs (added by them): $file"
            git checkout --theirs "$file"
            git add "$file"
            ;;
    esac
done

echo "✅ Batch conflict resolution completed. Please review the changes and commit."
